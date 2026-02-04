// Questo è un commento, volendo posso mettere qui il titolo dell'esperimento, i commenti non influenzano lo svolgimento del programma
// Determinazione della velocità del suono mediante Arduino
int trigPin = 2;                           //Definizione Pin di trigger: dai il via al segnale per iniziare ad emettere il suono
int echoPin = 4;                          //Definizione Pin di Eco: ascolta il suono riflesso
int i = 0;                                // definizione variabile del ciclo
int N = 50;                               // Quanti cicli di misurazione vogliamo?
void setup ()                            // inizializzazione del sensore
{
  Serial.begin (9600);                  //imposta la velocità di trasmissione
  pinMode(trigPin , OUTPUT );           // imposta questo pin come output (la scheda manda il segnale il pin la trasmette al sensore)
  pinMode(echoPin , INPUT );            // imposta questo pin come input (il sensore riceve il suono dell'eco e manda un segnale alla scheda)
  digitalWrite(trigPin , LOW);          //mandiamo un segnale basso all'emettitore di ultrasuoni
}

void loop()                             // inizio del programma vero e proprio
{

  digitalWrite(trigPin , LOW);
  for (i = 1; i <= N; i++)               // inizio del ciclo di ripetizione delle misure (N volte)
  {

    digitalWrite(trigPin , HIGH);         //mandiamo il segnale sonoro, lo impostiamo su Alto
    delayMicroseconds (10);               // aspetta 10 microsecondi
    digitalWrite(trigPin , LOW );         // abbassa il segnale
    long tUs = pulseIn(echoPin , HIGH);   // quando senti il suono dell'eco imposta il segnale in Alto
    delayMicroseconds (10);
    Serial.print(tUs);
    Serial.print("\n");            // aspetta 10 microsecondi                //aggiungi uno spazio                  // visualizza il tempo misurato è il tempo di andata e ritorno del suono
    delay (10);                          // delay è espresso in millisecondi quindi un valore di 100 corrisponde ad un decimo di secondo di pausa
    // aspettiamo un decimo di secondo tra una misurazione e l'altra
  }
  Serial.print("x\n");
  delay (10);                           // si attende un secondo prima di fare un altro ciclo di N misure // visualizza un separatore tra un set di misure e l'altro                    // vai a capo

}
