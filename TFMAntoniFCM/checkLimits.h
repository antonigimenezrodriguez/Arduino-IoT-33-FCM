#define MIN_VALUE_CO2 500.00
#define MAX_VALUE_CO2 700.00

#define MIN_VALUE_WATER 40.00
#define MAX_VALUE_WATER 90.00

#define MIN_VALUE_HUMIDITY 10.00
#define MAX_VALUE_HUMIDITY 80.00

#define MIN_VALUE_TEMPERATURE 15.00
#define MAX_VALUE_TEMPERATURE 30.00



bool outOfLimits(int sensor, float value) {
  Serial.print("entro switch limits, ");
  Serial.print("sensor: ");
  Serial.print(sensor);
  Serial.print(" Value: ");
  Serial.println(value);
  switch (sensor) {
    case 0:
      if (value < MIN_VALUE_CO2 || value > MAX_VALUE_CO2)
        return true;
      else
        return false;
      break;
    case 1:
      if (value < MIN_VALUE_WATER || value > MAX_VALUE_WATER)
        return true;
      else
        return false;
      break;
    case 2:
      if (value < MIN_VALUE_HUMIDITY || value > MAX_VALUE_HUMIDITY)
        return true;
      else
        return false;
      break;
    case 3:
      if (value < MIN_VALUE_TEMPERATURE || value > MAX_VALUE_TEMPERATURE)
        return true;
      else
        return false;
      break;
    default:
      return false;
  }

}
