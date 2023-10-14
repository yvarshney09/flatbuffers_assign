import struct
import sys
import flatbuffers
import ClientSchema.AnyClient as AnyClient
import ClientSchema.Person as Person
import ClientSchema.Group as Group
import ClientSchema.Client as Client
def decode_message(buffer):
    buf = bytearray(buffer)

    any_client = AnyClient.AnyClient.GetRootAsAnyClient(buf, 0)

    client_type = any_client.ClientType()
    if client_type == Client.Client().Person:
        person = Person.Person()
        person.Init(any_client.Client().Bytes,any_client.Client().Pos)
        return {
            "type": "Person",
            "name": person.Name(),
            "age": person.Age(),
            "weight": person.Weight(),
            "gender": person.Gender()
        }
    elif client_type == Client.Client().Group:
        group = Group.Group()
        group.Init(any_client.Client().Bytes,any_client.Client().Pos)
        names = [group.Names(i) for i in range(group.NamesLength())]
        return {
            "type": "Group",
            "group_name": group.GroupName(),
            "average_age": group.AverageAge(),
            "average_weight": group.AverageWeight(),
            "names": names
        }
    else:
        raise ValueError("Unknown client type")

def read_and_decode_messages(file_path):
    decoded_messages = []

    with open(file_path, "rb") as file:
        while True:
            size_data = file.read(4)
            if not size_data:
                break

            message_size = struct.unpack("<I", size_data)[0]

            message_data = file.read(message_size)

            decoded_message = decode_message(message_data)
            decoded_messages.append(decoded_message)

    return decoded_messages
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <path_to_binary_file>")
        sys.exit(1)

    binary_file_path = sys.argv[1]

    decoded_messages = read_and_decode_messages(binary_file_path)

    for i, message in enumerate(decoded_messages, start=1):
        print(f"Message {i}: {message}")


