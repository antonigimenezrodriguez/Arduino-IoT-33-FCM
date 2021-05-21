#include <SPI.h>

#define FCM_HOST "fcm.googleapis.com"
#define FCM_AUTH "AAAAUttm144:APA91bHpdrsqHn2eMygFE0TqOiRm_m1tCgOrGNY7p_38nfSaYDtepDKbVFHHCoynffHftHFL2h6JT_F5sFSBsmP0y04-gC7ryeeehvBmtM0dQz4TzjXlnHKzXnGXktOqKYtiSsBqAy9p "
#define CONTENT_TYPE "application/json"
#define CO2_TYPE 0
#define TEMP_TYPE 1
#define HUM_TYPE 2

WiFiSSLClient client;
void send_notification(uint16_t, int, uint8_t, String);
int getQuantityUsers();
String getTokenUser(int);

void send_notification(uint16_t val, int type, uint8_t isAuto, String sensorName) {

  int quantityUsers = getQuantityUsers();
  delay(100);
  Serial.print("Users: ");
  Serial.println(quantityUsers);
  delay(100);

  for (int i = 1; i <= quantityUsers ; i++) {
    String token = getTokenUser(i);
    Serial.print("Token usuario ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(token);

    String title, body;
    title = "Limite de " + sensorName + "sobrepasado";
    body = "Valor de " + sensorName + String(val);

    Serial.println("\tEnviando notificacion por sobrepasar limites");
    DynamicJsonDocument params(1024);
    params["to"] = token;
    params["notification"]["title"] = title;
    params["notification"]["body"] = body;
    params["data"]["tipo"] = type;
    params["data"]["value"] = val;
    params["data"]["auto"] = isAuto;
    params["data"]["click_action"] = "FLUTTER_NOTIFICATION_CLICK";

    String data;
    serializeJson(params, data);

    if (client.connect(FCM_HOST, 443)) {
      Serial.println("\tConectando con el servidor...");
      client.println("POST /fcm/send HTTP/1.1");
      client.println("Host: fcm.googleapis.com");
      client.println("Authorization: key=" + String(FCM_AUTH));
      client.println("Content-Type: application/json");
      client.print("Content-Length: ");
      client.println(data.length());
      client.print("\n");
      client.print(data);
    }
    Serial.println("\tDatos enviados");
    client.flush();
    client.stop();


  }



}

int getQuantityUsers() {
  String path = "/users/quantity";
  if (Firebase.getInt(firebaseData, path))
  {
    if (firebaseData.dataType() == "int")
      return firebaseData.intData();
    else if (firebaseData.dataType() == "float")
      return firebaseData.floatData();
  }
  else
  {
    Serial.println("----------Can't get data--------");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("--------------------------------");
    Serial.println();
  }
}

String getTokenUser(int i) {
  String route = "";
  route = "/users/" + String(i) + "/token";
  Serial.print("Ruta token usuario 1: ");
  Serial.println(route);
  if (Firebase.getString(firebaseData, route))
  {
    if (firebaseData.dataType() == "string")
      return firebaseData.stringData();
    else if (firebaseData.dataType() == "json")
      return firebaseData.jsonData();
  }
  else
  {
    Serial.println("----------Can't get data--------");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("--------------------------------");
    Serial.println();
  }
}
