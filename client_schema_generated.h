// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLIENTSCHEMA_CLIENTSCHEMA_H_
#define FLATBUFFERS_GENERATED_CLIENTSCHEMA_CLIENTSCHEMA_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

namespace ClientSchema {

struct Person;
struct PersonBuilder;

struct Group;
struct GroupBuilder;

struct AnyClient;
struct AnyClientBuilder;

enum Gender : int8_t {
  Gender_Male = 0,
  Gender_Female = 1,
  Gender_MIN = Gender_Male,
  Gender_MAX = Gender_Female
};

inline const Gender (&EnumValuesGender())[2] {
  static const Gender values[] = {
    Gender_Male,
    Gender_Female
  };
  return values;
}

inline const char * const *EnumNamesGender() {
  static const char * const names[3] = {
    "Male",
    "Female",
    nullptr
  };
  return names;
}

inline const char *EnumNameGender(Gender e) {
  if (::flatbuffers::IsOutRange(e, Gender_Male, Gender_Female)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesGender()[index];
}

enum Client : uint8_t {
  Client_NONE = 0,
  Client_Person = 1,
  Client_Group = 2,
  Client_MIN = Client_NONE,
  Client_MAX = Client_Group
};

inline const Client (&EnumValuesClient())[3] {
  static const Client values[] = {
    Client_NONE,
    Client_Person,
    Client_Group
  };
  return values;
}

inline const char * const *EnumNamesClient() {
  static const char * const names[4] = {
    "NONE",
    "Person",
    "Group",
    nullptr
  };
  return names;
}

inline const char *EnumNameClient(Client e) {
  if (::flatbuffers::IsOutRange(e, Client_NONE, Client_Group)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesClient()[index];
}

template<typename T> struct ClientTraits {
  static const Client enum_value = Client_NONE;
};

template<> struct ClientTraits<ClientSchema::Person> {
  static const Client enum_value = Client_Person;
};

template<> struct ClientTraits<ClientSchema::Group> {
  static const Client enum_value = Client_Group;
};

bool VerifyClient(::flatbuffers::Verifier &verifier, const void *obj, Client type);
bool VerifyClientVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<uint8_t> *types);

struct Person FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_AGE = 6,
    VT_WEIGHT = 8,
    VT_GENDER = 10
  };
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  float age() const {
    return GetField<float>(VT_AGE, 0.0f);
  }
  float weight() const {
    return GetField<float>(VT_WEIGHT, 0.0f);
  }
  ClientSchema::Gender gender() const {
    return static_cast<ClientSchema::Gender>(GetField<int8_t>(VT_GENDER, 0));
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<float>(verifier, VT_AGE, 4) &&
           VerifyField<float>(verifier, VT_WEIGHT, 4) &&
           VerifyField<int8_t>(verifier, VT_GENDER, 1) &&
           verifier.EndTable();
  }
};

struct PersonBuilder {
  typedef Person Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(Person::VT_NAME, name);
  }
  void add_age(float age) {
    fbb_.AddElement<float>(Person::VT_AGE, age, 0.0f);
  }
  void add_weight(float weight) {
    fbb_.AddElement<float>(Person::VT_WEIGHT, weight, 0.0f);
  }
  void add_gender(ClientSchema::Gender gender) {
    fbb_.AddElement<int8_t>(Person::VT_GENDER, static_cast<int8_t>(gender), 0);
  }
  explicit PersonBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Person> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Person>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Person> CreatePerson(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    float age = 0.0f,
    float weight = 0.0f,
    ClientSchema::Gender gender = ClientSchema::Gender_Male) {
  PersonBuilder builder_(_fbb);
  builder_.add_weight(weight);
  builder_.add_age(age);
  builder_.add_name(name);
  builder_.add_gender(gender);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Person> CreatePersonDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    float age = 0.0f,
    float weight = 0.0f,
    ClientSchema::Gender gender = ClientSchema::Gender_Male) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return ClientSchema::CreatePerson(
      _fbb,
      name__,
      age,
      weight,
      gender);
}

struct Group FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef GroupBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_GROUP_NAME = 4,
    VT_AVERAGE_AGE = 6,
    VT_AVERAGE_WEIGHT = 8,
    VT_NAMES = 10
  };
  const ::flatbuffers::String *group_name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_GROUP_NAME);
  }
  float average_age() const {
    return GetField<float>(VT_AVERAGE_AGE, 0.0f);
  }
  float average_weight() const {
    return GetField<float>(VT_AVERAGE_WEIGHT, 0.0f);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *names() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_NAMES);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GROUP_NAME) &&
           verifier.VerifyString(group_name()) &&
           VerifyField<float>(verifier, VT_AVERAGE_AGE, 4) &&
           VerifyField<float>(verifier, VT_AVERAGE_WEIGHT, 4) &&
           VerifyOffset(verifier, VT_NAMES) &&
           verifier.VerifyVector(names()) &&
           verifier.VerifyVectorOfStrings(names()) &&
           verifier.EndTable();
  }
};

struct GroupBuilder {
  typedef Group Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_group_name(::flatbuffers::Offset<::flatbuffers::String> group_name) {
    fbb_.AddOffset(Group::VT_GROUP_NAME, group_name);
  }
  void add_average_age(float average_age) {
    fbb_.AddElement<float>(Group::VT_AVERAGE_AGE, average_age, 0.0f);
  }
  void add_average_weight(float average_weight) {
    fbb_.AddElement<float>(Group::VT_AVERAGE_WEIGHT, average_weight, 0.0f);
  }
  void add_names(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> names) {
    fbb_.AddOffset(Group::VT_NAMES, names);
  }
  explicit GroupBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Group> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Group>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Group> CreateGroup(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> group_name = 0,
    float average_age = 0.0f,
    float average_weight = 0.0f,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> names = 0) {
  GroupBuilder builder_(_fbb);
  builder_.add_names(names);
  builder_.add_average_weight(average_weight);
  builder_.add_average_age(average_age);
  builder_.add_group_name(group_name);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Group> CreateGroupDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *group_name = nullptr,
    float average_age = 0.0f,
    float average_weight = 0.0f,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *names = nullptr) {
  auto group_name__ = group_name ? _fbb.CreateString(group_name) : 0;
  auto names__ = names ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*names) : 0;
  return ClientSchema::CreateGroup(
      _fbb,
      group_name__,
      average_age,
      average_weight,
      names__);
}

struct AnyClient FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef AnyClientBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLIENT_TYPE = 4,
    VT_CLIENT = 6
  };
  ClientSchema::Client client_type() const {
    return static_cast<ClientSchema::Client>(GetField<uint8_t>(VT_CLIENT_TYPE, 0));
  }
  const void *client() const {
    return GetPointer<const void *>(VT_CLIENT);
  }
  template<typename T> const T *client_as() const;
  const ClientSchema::Person *client_as_Person() const {
    return client_type() == ClientSchema::Client_Person ? static_cast<const ClientSchema::Person *>(client()) : nullptr;
  }
  const ClientSchema::Group *client_as_Group() const {
    return client_type() == ClientSchema::Client_Group ? static_cast<const ClientSchema::Group *>(client()) : nullptr;
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_CLIENT_TYPE, 1) &&
           VerifyOffset(verifier, VT_CLIENT) &&
           VerifyClient(verifier, client(), client_type()) &&
           verifier.EndTable();
  }
};

template<> inline const ClientSchema::Person *AnyClient::client_as<ClientSchema::Person>() const {
  return client_as_Person();
}

template<> inline const ClientSchema::Group *AnyClient::client_as<ClientSchema::Group>() const {
  return client_as_Group();
}

struct AnyClientBuilder {
  typedef AnyClient Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_client_type(ClientSchema::Client client_type) {
    fbb_.AddElement<uint8_t>(AnyClient::VT_CLIENT_TYPE, static_cast<uint8_t>(client_type), 0);
  }
  void add_client(::flatbuffers::Offset<void> client) {
    fbb_.AddOffset(AnyClient::VT_CLIENT, client);
  }
  explicit AnyClientBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<AnyClient> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<AnyClient>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<AnyClient> CreateAnyClient(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ClientSchema::Client client_type = ClientSchema::Client_NONE,
    ::flatbuffers::Offset<void> client = 0) {
  AnyClientBuilder builder_(_fbb);
  builder_.add_client(client);
  builder_.add_client_type(client_type);
  return builder_.Finish();
}

inline bool VerifyClient(::flatbuffers::Verifier &verifier, const void *obj, Client type) {
  switch (type) {
    case Client_NONE: {
      return true;
    }
    case Client_Person: {
      auto ptr = reinterpret_cast<const ClientSchema::Person *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Client_Group: {
      auto ptr = reinterpret_cast<const ClientSchema::Group *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyClientVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (::flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyClient(
        verifier,  values->Get(i), types->GetEnum<Client>(i))) {
      return false;
    }
  }
  return true;
}

inline const ClientSchema::AnyClient *GetAnyClient(const void *buf) {
  return ::flatbuffers::GetRoot<ClientSchema::AnyClient>(buf);
}

inline const ClientSchema::AnyClient *GetSizePrefixedAnyClient(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<ClientSchema::AnyClient>(buf);
}

inline bool VerifyAnyClientBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<ClientSchema::AnyClient>(nullptr);
}

inline bool VerifySizePrefixedAnyClientBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<ClientSchema::AnyClient>(nullptr);
}

inline void FinishAnyClientBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<ClientSchema::AnyClient> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedAnyClientBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<ClientSchema::AnyClient> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace ClientSchema

#endif  // FLATBUFFERS_GENERATED_CLIENTSCHEMA_CLIENTSCHEMA_H_