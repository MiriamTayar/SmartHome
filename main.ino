

void setup() {
  // setup_enroll();
  // setup_fingerprint();
  setup_gas();
  setup_light_sensor();
  setup_temperature();
}


void loop() {
  // loop_enroll();
  // loop_fingerprint();
  gas_test();
  light_sensor();
  is_hot();
}