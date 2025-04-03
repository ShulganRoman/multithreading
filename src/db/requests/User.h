#include "Creatable.h"
#include <string>

class User : public Creatable {
public:
  explicit User(std::string name, std::string fieldName)
      : _name(name), _fieldName(fieldName) {}

  std::string getString() override { return ""; } // TODO: returnable value

  ~User() = default;

private:
  std::string _name;
  std::string _fieldName;
};
