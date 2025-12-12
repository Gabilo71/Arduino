// ================== ENTRADAS (INPUT_PULLUP, activas LOW) ==================
const int FC_Delante       = 2;   // LOW cuando toca final delante
const int FC_Trasero       = 3;   // LOW cuando toca final atrás
const int FC_Pieza_entrada  = 5;   // LOW cuando hay pieza delante
const int FC_Pieza_salida   = 6;   // LOW cuando hay pieza detrás
const int Boton_Start      = 4;   // LOW al pulsar

// ================== SALIDAS ==================
const int Motor_AvanceA     = 9;
const int Motor_AvanceB     = 10;
const int Motor_RetroA      = 11;
const int Motor_RetroB      = 12;
const int Electroiman      = 13;

// ============================================================
bool automatico = false;   // Solo inicia tras pulsar START
unsigned long delay_suelta = 1000;  // Retardo tras liberar zona trasera

void setup() {
  pinMode(FC_Delante, INPUT_PULLUP);
  pinMode(FC_Trasero, INPUT_PULLUP);
  pinMode(FC_Pieza_entrada, INPUT_PULLUP);
  pinMode(FC_Pieza_salida, INPUT_PULLUP);
  pinMode(Boton_Start, INPUT_PULLUP);

  pinMode(Motor_AvanceA, OUTPUT);
  pinMode(Motor_AvanceB, OUTPUT);
  pinMode(Motor_RetroA, OUTPUT);
  pinMode(Motor_RetroB, OUTPUT);
  pinMode(Electroiman, OUTPUT);

  detenerMotor();
  digitalWrite(Electroiman, LOW);

  Serial.begin(9600);

  posicion_inicial();   // Se posiciona atras al iniciar

  Serial.println("Esperando botón START para iniciar ciclo automático...");
}

// ============================================================

void loop() {

  // ----------- ESPERA PRIMERA PULSACIÓN PARA EMPEZAR -----------
  if (!automatico) {
    if (digitalRead(Boton_Start) == LOW) { // pulsado -> activo
      automatico = true;
      Serial.println(">>> Ciclo automático INICIADO");
      delay(300);   // antirrebote básico
    }
    return;
  }

  // ===================== CICLO AUTOMÁTICO CONTINUO =======================

  // Si hay pieza en la parte delantera -> recoger
  if (digitalRead(FC_Pieza_entrada) == LOW) {
    Serial.println("Hay pieza delante, yendo a recoger...");

    moverAdelante();
    while (digitalRead(FC_Delante) == HIGH); // Espera llegar al FC
    detenerMotor();

    digitalWrite(Electroiman, HIGH); // Coger pieza
    delay(200);

    moverAtras();
    while (digitalRead(FC_Trasero) == HIGH); // Espera llegar atrás
    detenerMotor();

    // Si NO hay pieza detrás -> soltar
    if (digitalRead(FC_Pieza_salida) == HIGH) {
      Serial.println("Zona trasera libre -> dejando pieza");
      digitalWrite(Electroiman, LOW);
      delay(300);
    } 
    else {
      Serial.println("Zona trasera ocupada, esperando a que retiren...");
      while (digitalRead(FC_Pieza_salida) == LOW);  // espera que quiten
      delay(delay_suelta);
      digitalWrite(Electroiman, LOW);
      Serial.println("Pieza depositada");
    }
  }

  // Si no hay pieza delante pero sí detrás -> espera retirada
  else if (digitalRead(FC_Pieza_salida) == LOW) {
    Serial.println("Esperando a que retiren pieza trasera...");
    while (digitalRead(FC_Pieza_salida) == LOW);
    delay(500);
  }

  else {
    Serial.println("Sin piezas disponibles -> esperando ciclo...");
    delay(300);
  }
}

// ============================================================
// ------------------------ FUNCIONES -------------------------

