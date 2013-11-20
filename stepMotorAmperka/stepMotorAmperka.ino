#include <TimerOne.h>
 
void setup() 
{
  pinMode(8, OUTPUT);   // Drive Select 1 (выбор двигателя 1)
  pinMode(9, OUTPUT);   // DIRECTION (направление вращения)
  pinMode(10, OUTPUT);  // Head Step (шаг)
  pinMode(13, OUTPUT);  // led

  digitalWrite( 9, 0 ); // (стартовое направление - вперед)
  digitalWrite( 8, 0 ); // select Drive (двигатель включается нулем)
  digitalWrite( 10, 0 ); // step prepare (начинаем с нуля. Шаг будет выглядеть так -> _п_)
  
  // Настройка прерывания по таймеру. Он будет тикать раз в секунду    
  Timer1.initialize(1000000); // set a timer of length 1000000 microseconds (or 1 sec)
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here (эта функция будет вызвана в прерывании)
}
 
void loop()
{
  // Main code loop
  // Здесь мы будем шагать
  digitalWrite( 10, 1 );
  digitalWrite( 10, 0 );  
  delay(20); // Пауза между шагами. Чем меньше задержка, тем выше скорость вращения.
}
 
/// --------------------------
/// Custom ISR Timer Routine
/// --------------------------
void timerIsr()
{
    // Меняем направление вращения    
    digitalWrite( 9, digitalRead( 9 ) ^ 1 );
    digitalWrite( 13, digitalRead( 13 ) ^ 1 );

}
