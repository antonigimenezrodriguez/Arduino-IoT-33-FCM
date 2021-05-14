
#include <SPI.h>
#include <WiFiNINA.h>

#define FCM_HOST "fcm.googleapis.com"
#define FCM_AUTH "AAAAUttm144:APA91bHpdrsqHn2eMygFE0TqOiRm_m1tCgOrGNY7p_38nfSaYDtepDKbVFHHCoynffHftHFL2h6JT_F5sFSBsmP0y04-gC7ryeeehvBmtM0dQz4TzjXlnHKzXnGXktOqKYtiSsBqAy9p "
#define CONTENT_TYPE "application/json"
#define CO2_TYPE 0
#define TEMP_TYPE 1
#define HUM_TYPE 2
#define PHONE_ID_EMULADOR "eoruK0bDGPM:APA91bGiLwQp-mB6SA_Rgb38piHgW7CdfqVV6qf14Y3RQeH-LN-Qpg6hPKCfW3ezvSS0zkDGgCOZFMbAHSC_4TFslv3UbXuQffaQ7Bq1Ub8nMPNlpRf_c9USpVRenqII0AyE5zG77rtx"

WiFiSSLClient client;
void send_notification(uint16_t, int, uint8_t);

void send_notification(uint16_t val, int type, uint8_t isAuto) {
  String title, body;
  title = "Limite de CO2 sobrepasado";
  body = "Valor de CO2: " + String(val) + " ppm.";

  Serial.println("\tEnviando notificacion por sobrepasar limites");
  DynamicJsonDocument params(1024);
  params["to"] = PHONE_ID_EMULADOR;
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
