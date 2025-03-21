#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для подсчета количества вхождений буквы в строку
int countLetter(const char *str, char letter) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == letter) {
      count++;
    }
  }
  return count;
}

int main() {
  char **sentences = NULL; // Указатель на массив строк (предложений)
  char letter;        // Переменная для хранения буквы
  int totalCount = 0; // Общее количество вхождений буквы
  int sentenceCount = 0; // Количество предложений
  char buffer[1000]; // Буфер для считывания предложений

  // Ввод предложений с клавиатуры
  printf("Введите букву: ");
  scanf(" %c", &letter);
  getchar(); // Очистка буфера

  // Ввод предложений
  printf("Введите предложения (для завершения ввода введите пустую строку):\n");
  while (1) {
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 

    if (strlen(buffer) == 0) {
      break; // Выход из цикла при пустой строке
    }

    sentences =
        (char **)realloc(sentences, (sentenceCount + 1) * sizeof(char *));
    sentences[sentenceCount] =
        (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(sentences[sentenceCount], buffer);

    sentenceCount++;
  }
  // Подсчет количества вхождений буквы
  for (int i = 0; i < sentenceCount; i++) {
    totalCount += countLetter(sentences[i], letter);
  }

  printf("Общее количество буквы '%c' в предложениях: %d\n", letter,
         totalCount);

  // Освобождение памяти
  for (int i = 0; i < sentenceCount; i++) {
    free(sentences[i]);
  }
  free(sentences);

  return 0;
}