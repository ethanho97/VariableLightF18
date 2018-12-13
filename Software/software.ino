// use preprocessor directives to define constants in the code
#define FLASH_RATE_HZ 2
#define BUTTON_PIN 4
#define LED_PIN 12
#define PWN_LED_OUT D11
#define PWM_MAX 255
#define NUM_MODE 5

// global variables representing "state" across all functions
// operating mode: 0 - off, 1 - bright, 2 - mid-bright, 3 - dim, 4 - flash
int operating_mode = 0;
bool button_press = false;
int previous_button_state = 0;
int PWM_OUT = 0;

// executed one-time at device startup
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_pushed, FALLING);
   // define output (PWM) pin connected to LED
}

// continually-running loop
// calls functions that are named as "actions"
void loop(){
    check_button_press();
    set_pwm();
    shine_led(PWM_OUT);
}

void set_pwm() {

    switch (operating_mode) {
        case 0:
            PWM_OUT = 0;
        case 1:
            PWM_OUT = PWM_MAX;
        case 2:
            PWM_OUT = int(PWM_MAX/2);
        case 3:
            PWM_OUT = int(PWM_MAX/4);
        case 4:
            PWM_OUT = PWM_MAX;
            flash_the_light();
    }

}

void button_pushed() {
    button_press = true;
}

void flash_the_light() {
    analogWrite(LED_PIN, PWM_OUT);
    delay(1000);
}

void shine_led(int PWN) {
    analogWrite(LED_PIN, PWM_OUT);
}

void check_button_press() {
    if (button_press){
        if (operating_mode > NUM_MODE - 1){
            operating_mode = 0;
        }else {
            operating_mode++;
        }
        button_press = false;
    }
}
