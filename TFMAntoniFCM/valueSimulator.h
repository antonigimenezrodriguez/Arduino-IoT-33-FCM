String sensors[] = {"CO2", "Water", "Humidity", "Temperature"};

void getRandomValue(float &value, String &sensorName, int &sensor) {
  sensor = random(0, 4);
  sensorName = sensors[sensor];
  switch (sensor) {
    case 0:
      value = random(300, 900);
      break;
    case 1:
      value = random(0, 100);
      break;
    case 2:
      value = random(0, 100);
      break;
    case 3:
      value = random(-10, 50);
      break;
    default:
      break;
  }
}
