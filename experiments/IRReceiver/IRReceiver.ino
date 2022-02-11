#define IR_IN A0
#define IR_LED 22

void setup()
{
    pinMode(IR_LED, OUTPUT);
    pinMode(IR_IN, INPUT);
    digitalWrite(IR_LED, LOW);
    Serial.begin(115200);
    Serial.println("Ready!");
}

int sensor = 0;

void loop()
{
    sensor = analogRead(IR_IN);
    Serial.println(sensor);
}
