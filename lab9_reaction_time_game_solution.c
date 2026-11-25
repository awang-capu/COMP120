// Part 1 sample solution
const int LED_PIN = 12;
const int BUTTON_PIN = 7;
const int RANDOM_NUM_MIN = 3000;
const int RANDOM_NUM_MAX = 5000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  randomSeed(0);
  Serial.begin(9600);
  delay(5000);
  Serial.println("Reaction-time game starts!");
}

void loop() {
  int rand_num = random(RANDOM_NUM_MIN,RANDOM_NUM_MAX);  // Generated random number
  delay(rand_num);

  int button_state = digitalRead(BUTTON_PIN);

  digitalWrite(LED_PIN, HIGH);   // Turn the LED on (HIGH is the voltage level)
  unsigned long t1 = millis();

  while (button_state == LOW)
    button_state = digitalRead(BUTTON_PIN);

  digitalWrite(LED_PIN, LOW);
  unsigned long t2 = millis();

  Serial.print("You got it in ");
  Serial.print(t2 - t1);
  Serial.println(" milliseconds.");
  
  delay(1000);
  Serial.println("New round!");
}


// Part 2 sample solution
const int LED_PIN = 12;
const int BUTTON_PIN = 7;
const int RANDOM_NUM_MIN = 3000;
const int RANDOM_NUM_MAX = 5000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  randomSeed(0);
  Serial.begin(9600);
  delay(5000);
  Serial.println("Reaction-time game starts!");
}

void loop() {
  int rand_num = random(RANDOM_NUM_MIN,RANDOM_NUM_MAX);  // Generated random number
  delay(rand_num);

  int button_state = digitalRead(BUTTON_PIN);

  // Only add the following if statement onto the part 1's solution
  if (button_state == HIGH) {
    Serial.println("Release the button before the game!");
    while (digitalRead(BUTTON_PIN) == HIGH) {} // digitalRead(BUTTON_PIN) instead of buttonState
    Serial.println("New round!");
    return;
  }

  digitalWrite(LED_PIN, HIGH);   // Turn the LED on (HIGH is the voltage level)
  unsigned long t1 = millis();

  while (button_state == LOW)
    button_state = digitalRead(BUTTON_PIN);

  digitalWrite(LED_PIN, LOW);
  unsigned long t2 = millis();

  Serial.print("You got it in ");
  Serial.print(t2 - t1);
  Serial.println(" milliseconds.");
  
  delay(1000);
  Serial.println("New round!");
}
