struct Control {
  int pin;
};

void ctrlPinMode(void* control, int mode) {
  Control* ctrl = (Control*)control;
  pinMode(ctrl->pin, mode);
}

int ctrlDigitalRead(void* control) {
  Control* ctrl = (Control*)control;
  return digitalRead(ctrl->pin);
}

void ctrlDigitalWrite(void* control, int value) {
  Control* ctrl = (Control*)control;
  digitalWrite(ctrl->pin, value);
}

void* gLed;
void* gButton;

void setupLed() {
  Control* ctrl = new Control();
  ctrl->pin = 13;
  ctrlPinMode(ctrl, OUTPUT);
  gLed = ctrl;
}

void setupButton() {
  Control* ctrl = new Control();
  ctrl->pin = 7;
  ctrlPinMode(ctrl, INPUT);
  gButton = ctrl;
}

void setup() {
  setupLed();
  setupButton();
}

void loop() {
  int val = ctrlDigitalRead(gButton);
  if (val == HIGH) {
    ctrlDigitalWrite(gLed, HIGH);
  } else {
    ctrlDigitalWrite(gLed, LOW);
  }
}