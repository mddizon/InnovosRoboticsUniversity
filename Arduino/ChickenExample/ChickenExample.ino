int player1Count = 0;
int player2Count = 0;
int player1 = 0;
int player2 = 0;
int gameState = 0;
int START = 0;
int PLAY = 1;
int RESULT = 2;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
  Serial.println("The game will start when both buttons are pressed");
}

void loop() {
  player1 = digitalRead(2);
  player2 = digitalRead(13);

  if (gameState == START) {
    if (player1 == HIGH && player2 == HIGH) {
      gameState = 1;
    }
  } else if (gameState == PLAY) {

    if (player1 == LOW && player2 == LOW) {
      gameState = 2;
    } else {
      if (player1 == HIGH) {
        player1Count = player1Count + 1;
        if (player1Count > 0) {
          digitalWrite(3, HIGH);
        }
        if (player1Count > 1) {
          digitalWrite(4, HIGH);
        }
        if (player1Count > 2) {
          digitalWrite(5, HIGH);
        }
        if (player1Count > 3) {
          digitalWrite(6, HIGH);
        }
        if (player1Count > 4) {
          digitalWrite(7, HIGH);
          player1Count = -99;
        }
      }

      if (player2 == HIGH) {
        player2Count = player2Count + 1;
        if (player2Count > 0) {
          digitalWrite(12, HIGH);
        }
        if (player2Count > 1) {
          digitalWrite(11, HIGH);
        }
        if (player2Count > 2) {
          digitalWrite(10, HIGH);
        }
        if (player2Count > 3) {
          digitalWrite(9, HIGH);
        }
        if (player2Count > 4) {
          digitalWrite(7, HIGH);
          player2Count = -99;
        }
      }
      delay(random(250, 1001));
    }
  } else if (gameState == RESULT) {
    if (player1Count > player2Count) {
      Serial.println("Player 1 Wins!");
    } else if (player2Count > player1Count){
      Serial.println("Player 2 Wins!");
    } else {
      Serial.println("It's a draw!");
    }
    gameState = 3;
  } else {
    gameState = 0;
    player1Count = 0;
    player2Count = 0;
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    Serial.println("The game will start when both buttons are pressed");
  }

}