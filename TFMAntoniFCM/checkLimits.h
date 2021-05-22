#define MIN_VALUE_CO2 500.00
#define MAX_VALUE_CO2 700.00

#define MIN_VALUE_WATER 60.00
#define MAX_VALUE_WATER 80.00

#define MIN_VALUE_HUMIDITY 30.00
#define MAX_VALUE_HUMIDITY 60.00

#define MIN_VALUE_TEMPERATURE 15.00
#define MAX_VALUE_TEMPERATURE 30.00



bool outOfLimits(int sensor, float value) {

  switch (sensor) {
    case 0:
      if (value < MIN_VALUE_CO2 || value > MAX_VALUE_CO2)
        return true;
      else
        return false;
      break;
    case 1:
      if (value < MIN_VALUE_CO2 || value > MAX_VALUE_CO2)
        return true;
      else
        return false;
      break;
    case 2:
      if (value < MIN_VALUE_CO2 || value > MAX_VALUE_CO2)
        return true;
      else
        return false;
      break;
    case 3:
      if (value < MIN_VALUE_CO2 || value > MAX_VALUE_CO2)
        return true;
      else
        return false;
      break;
    default:
      return false;
  }

}
