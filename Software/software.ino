// use preprocessor directives to define constants in the code
#define FLASH_RATE_HZ 2
#define BUTTON_PIN 3
#define LED_PIN 11
#define PWM_MAX 255
#define NUM_MODE 5

int operating_mode = 0;
bool button_press = false;
int PWM_OUT = 0;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_pushed, FALLING);
}

void loop(){
  check_button_press();
  set_pwm();
}

void set_pwm() {
  switch (operating_mode) {
    case 0:
      PWM_OUT = 0;
      shine_led(PWM_OUT);
//      Serial.println(PWM_OUT);
      break;
    case 1:
      PWM_OUT = PWM_MAX;
      shine_led(PWM_OUT);
//      Serial.println(PWM_OUT);
      break;
    case 2:
      PWM_OUT = int(PWM_MAX/2);
      shine_led(PWM_OUT);
//      Serial.println(PWM_OUT);
      break;
    case 3:
      PWM_OUT = int(PWM_MAX/4);
      shine_led(PWM_OUT);
//      Serial.println(PWM_OUT);
      break;
    case 4:
//      Serial.println(PWM_OUT);
      flash_the_light();
      break;
    }
}

void button_pushed() {
  if ( (millis() - lastDebounceTime) > debounceDelay) {
    button_press = true;
    lastDebounceTime = millis();
    Serial.println(operating_mode);
  }
}

void flash_the_light() {
  analogWrite(LED_PIN, PWM_MAX);
  delay(1000/FLASH_RATE_HZ);
  analogWrite(LED_PIN, 0);
  delay(1000/FLASH_RATE_HZ);
}

void shine_led(int PWM) {
  analogWrite(LED_PIN, PWM);
}

void check_button_press() {
  if (button_press){
    if (operating_mode == NUM_MODE - 1){
      operating_mode = 0;
    }else {
      operating_mode++;
    }
      button_press = false;
  }
}
