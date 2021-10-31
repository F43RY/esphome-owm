class OpenWeathermapClient : public PollingComponent {
 public:
  Adafruit_BMP085 bmp;
  Sensor *temperature_sensor = new Sensor();
  Sensor *pressure_sensor = new Sensor();

  MyCustomSensor() : PollingComponent(15000) { }

  void setup() override {
    bmp.begin();
  }

  void update() override {
    // This is the actual sensor reading logic.
    float temperature = bmp.readTemperature();
    temperature_sensor->publish_state(temperature);

    int pressure = bmp.readPressure();
    pressure_sensor->publish_state(pressure / 100.0);
  }
};