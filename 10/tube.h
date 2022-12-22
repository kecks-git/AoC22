#include <optional>
#include <vector>

using llint = long long int;

struct Tube {
  explicit Tube(const std::vector<llint> &_signalStrength)
      : signalStrength(_signalStrength){};

  std::vector<llint> signalStrength{};
  llint getSignalStrength(const std::vector<int> &indices);

  void iterate(std::optional<llint> add);
  llint currentValue{1};

  void drawScreen();
};