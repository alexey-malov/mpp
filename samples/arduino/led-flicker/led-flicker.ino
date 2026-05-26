#include <avr/sleep.h>

ISR(TIMER1_COMPA_vect) {
    PORTB ^= (1 << PB5);
    ++value;
}

void setup() {
    cli();

    DDRB |= (1 << PB5);

    TCCR1A = 0;
    TCNT1 = 0;
    TCCR1B = (1 << WGM12);

    // Теперь задаём значение сравнения.
    OCR1A = 16000000 / 1024 / 2 -1;

    TCCR1B |= (1 << CS12) | (1 << CS10);

    TIMSK1 |= (1 << OCIE1A);

    sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  sleep_mode();
}
