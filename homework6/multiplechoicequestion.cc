// Minh My Tran - csce 240 - 003

#include "multiplechoicequestion.h"
#include <iostream>

namespace csce240_program5 {

MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int n, string *choices, bool *correct) : Question(q), num_choices_(n) {
  if (n > 0) {
    choices_ = new string[n];
    correct_ = new bool[n];
    if (choices != nullptr && correct != nullptr) {
      for (int i = 0; i < n; ++i) {
        choices_[i] = choices[i];
        correct_[i] = correct[i];
      }
    } else if (choices != nullptr) {
      for (int i = 0; i < n; ++i) {
        choices_[i] = choices[i];
        correct_[i] = true;
      }
    } else {
      for (int i = 0; i < n; ++i) {
        choices_[i] = "";
        correct_[i] = true;
      }
    }
  } else {
    choices_ = nullptr;
    correct_ = nullptr;
  }
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion &other) : Question(other.GetQuestion()), num_choices_(other.num_choices_) {
  if (num_choices_ > 0) {
    choices_ = new string[num_choices_];
    correct_ = new bool[num_choices_];
    for (int i = 0; i < num_choices_; ++i) {
      choices_[i] = other.choices_[i];
      correct_[i] = other.correct_[i];
    }
  } else {
    choices_ = nullptr;
    correct_ = nullptr;
  }
}

MultipleChoiceQuestion& MultipleChoiceQuestion::operator=(const MultipleChoiceQuestion &other) {
  if (this != &other) {
    Question::operator=(other);
    num_choices_ = other.num_choices_;
    delete[] choices_;
    delete[] correct_;
    if (num_choices_ > 0) {
      choices_ = new string[num_choices_];
      correct_ = new bool[num_choices_];
      for (int i = 0; i < num_choices_; ++i) {
        choices_[i] = other.choices_[i];
        correct_[i] = other.correct_[i];
      }
    } else {
      choices_ = nullptr;
      correct_ = nullptr;
    }
  }
  return *this;
}

MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  delete[] choices_;
  delete[] correct_;
}

void MultipleChoiceQuestion::SetNumChoices(int n) {
  num_choices_ = n;
}

int MultipleChoiceQuestion::GetNumChoices() const {
  return num_choices_;
}

void MultipleChoiceQuestion::SetChoices(string *choices) {
  delete[] choices_;
  if (num_choices_ > 0 && choices != nullptr) {
    choices_ = new string[num_choices_];
    for (int i = 0; i < num_choices_; ++i)
      choices_[i] = choices[i];
  } else
    choices_ = nullptr;
}

string* MultipleChoiceQuestion::GetChoices() const {
    return choices_;
}

void MultipleChoiceQuestion::SetCorrect(bool *correct) {
  delete[] correct_;
  if (num_choices_ > 0 && correct != nullptr) {
    correct_ = new bool[num_choices_];
    for (int i = 0; i < num_choices_; ++i)
      correct_[i] = correct[i];
  } else
    correct_ = nullptr;
}

bool* MultipleChoiceQuestion::GetCorrect() const {
  return correct_;
}

void MultipleChoiceQuestion::Print(bool show_answer) const {
  Question::Print();
  std::cout << "Answer Choices:" << std::endl;
  for (int i = 0; i < num_choices_; ++i) {
    std::cout << choices_[i];
    if (show_answer)
      std::cout << " - " << (correct_[i] ? "correct" : "incorrect");
    std::cout << std::endl;
  }
}

void MultipleChoiceQuestion::SetAnswerChoices(int n, string *choices, bool *correct) {
  SetNumChoices(n);
  SetChoices(choices);
  SetCorrect(correct);
}

bool MultipleChoiceQuestion::CheckAnswer(string answer) const {
    for (int i = 0; i < num_choices_; ++i) {
        if (answer == choices_[i] && correct_[i] == true)
            return true;
    }
    return false;
}


}  // namespace csce240_program5