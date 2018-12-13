// use preprocessor directives to define constants in the code
#define FLASH_RATE_HZ 2
#define LED_PIN D4
#define BUTTON_PIN D1
#define PWN_LED_OUT D11
#define PWM_MAX 255
#define NUM_MODE 5

// global variables representing "state" across all functions
// operating mode: 0 - off, 1 - bright, 2 - mid-bright, 3 - dim, 4 - flash
int operating_mode = 0;
bool button_pushed = TRUE;
int previous_button_state = 0;
int PWM_OUT = 0;

// executed one-time at device startup
void setup() {
  Serial.begin(9600);
  attachInterrupt(BUTTON_IN, button_pushed, FALLING);
   // define output (PWM) pin connected to LED

}

// continually-running loop
// calls functions that are named as "actions"
void loop(){

    check_for_button_press();

    set_pwm_based_on_operating_mode();

    shine_led();

}

void set_pwn_based_on_operating_mode() {

    switch (operating_mode) {
        case 0:
            PWM_OUT = 0;
        case 1:
            PWM_OUT = PWM_MAX;
        case 2:
            PWN_OUT = int(PWM_MAX/2);
        case 3:
            PWN_OUT = int(PWM_MAX/4);
        case 4:
            flash_the_light();
    }

}

void button_pushed() {
    BUTTON_PUSHED = TRUE;
}

void flash_the_light() {
    digitalOutput(magic_in_here);
    delay(1000);
}

void shine_led(PWN_OUT) {
    digitalOutput(magic_in_here);
}

void check_button_press() {
    // set operating_mode
    // reset previous button press state, interrupt catch, etc.

    // initialize button some way
    if (button){
        if (operating_mode > NUM_MODES){
            operating_mode = 0
        }else {
            operating_mode++
        }
    }
}
