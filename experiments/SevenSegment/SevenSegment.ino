int latchPin = 28;
int clockPin = 26;
int dataPin = 24;

int left = 3;
int right = 4;

int display(int value, bool period)
{
    int periodBit = 0;
    if (period)
    {
        periodBit = 0b10000000;
    }

    int result = 0;
    switch (value)
    {
    case 0:
        result = 0b01111110;
        break;
    case 1:
        result = 0b01001000;
        break;
    case 2:
        result = 0b00111101;
        break;
    case 3:
        result = 0b01101101;
        break;
    case 4:
        result = 0b01001011;
        break;
    case 5:
        result = 0b01100111;
        break;
    case 6:
        result = 0b01110111;
        break;
    case 7:
        result = 0b01001100;
        break;
    case 8:
        result = 0b01111111;
        break;
    case 9:
        result = 0b01001111;
        break;
    default:
        return 0;
    }

    return periodBit | result;
}

void setup()
{
    Serial.begin(9600);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(left, OUTPUT);
    pinMode(right, OUTPUT);
}

int value = 0;
unsigned long time = millis();
void loop()
{
    if (millis() - time > 500)
    {
        time = millis();
        value++;
        value = value % 100;
        Serial.println(value);
    }

    // LEFT SIDE
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, display(value / 10, value % 2 == 1));
    digitalWrite(latchPin, HIGH);
    digitalWrite(left, LOW);
    digitalWrite(right, HIGH);

    // RIGHT SIDE
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, display(value % 10, value % 2 == 0));
    digitalWrite(latchPin, HIGH);
    digitalWrite(left, HIGH);
    digitalWrite(right, LOW);
}