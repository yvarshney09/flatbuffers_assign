#include "flatbuffers/include/flatbuffers/flatbuffers.h"
#include "client_schema_generated.h"
#include <fstream>
using namespace ClientSchema;
flatbuffers::Offset<AnyClient> CreatePersonClient(flatbuffers::FlatBufferBuilder& builder) {
    std::string name = "Ram";
    float age = 21.0;
    float weight = 76.5;
    Gender gender = Gender::Gender_Male;

    // Create a Person
    auto person = CreatePerson(builder, builder.CreateString(name), age, weight, gender);

    // Create the Client as a Person
    auto client = CreateAnyClient(builder, Client_Person, person.Union());

    return client;
}

flatbuffers::Offset<AnyClient> CreateGroupClient(flatbuffers::FlatBufferBuilder& builder) {
    std::string groupName = "FightClub";
    float averageAge = 24.5;
    float averageWeight = 66.0;

    // Create names for the group
    std::vector<flatbuffers::Offset<flatbuffers::String>> names;
    names.push_back(builder.CreateString("Ram"));
    names.push_back(builder.CreateString("Shyam"));
    names.push_back(builder.CreateString("Raghuveer"));

    // Create a vector of names
    auto namesVector = builder.CreateVector(names);

    // Create a Group
    auto group = CreateGroup(builder, builder.CreateString(groupName), averageAge, averageWeight, namesVector);

    // Create the Client as a Group
    auto client = CreateAnyClient(builder, Client_Group, group.Union());

    return client;
}

void WriteToFile(const std::string& filename, const uint8_t* buf, int size, std::ios_base::openmode mode) {
    std::ofstream file(filename, std::ios::binary | mode);
    file.write(reinterpret_cast<const char*>(buf), size);
    file.close();
}

int main() {
    flatbuffers::FlatBufferBuilder builder;

    flatbuffers::Offset<AnyClient> personClientOffset = CreatePersonClient(builder);
    builder.FinishSizePrefixed(personClientOffset);

    const uint8_t* personBuf = builder.GetBufferPointer();
    int personSize = builder.GetSize();

    WriteToFile("fb_bytes.bin", personBuf, personSize,std::ios::out);

    builder.Clear();

    flatbuffers::Offset<AnyClient> groupClientOffset = CreateGroupClient(builder);
    builder.FinishSizePrefixed(groupClientOffset);

    const uint8_t* groupBuf = builder.GetBufferPointer();
    int groupSize = builder.GetSize();

    WriteToFile("fb_bytes.bin", groupBuf, groupSize,std::ios::app);

    return 0;
}

