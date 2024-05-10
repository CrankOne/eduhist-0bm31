#include "G4VUserActionInitialization.hh"

namespace edu0bm31 {

class ActionInitialization : public G4VUserActionInitialization {
  public:
    ActionInitialization() = default;
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;
};

}
