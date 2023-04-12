// Minh My Tran - csce 240 - 003


#include<string>
using std::string;

#ifndef _MULTIPLECHOICEQUESTION_H_
#define _MULTIPLECHOICEQUESTION_H_

#include "Question.h"
#include <string>

namespace csce240_program5 {

class MultipleChoiceQuestion : public Question {
 public:
  explicit MultipleChoiceQuestion(string q = "?", int n = 0, string *choices = nullptr, bool *correct = nullptr);
  MultipleChoiceQuestion(const MultipleChoiceQuestion &other);
  MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion &other);
  ~MultipleChoiceQuestion();
  void SetNumChoices(int n);
  int GetNumChoices() const;
  void SetChoices(string *choices);
  string* GetChoices() const;
  void SetCorrect(bool *correct);
  bool* GetCorrect() const;
  void Print(bool show_answer = false) const;
  void SetAnswerChoices(int n, string *choices, bool *correct);
 private:
  int num_choices_;
  string *choices_;
  bool *correct_;
};

}  // namespace csce240_program5

#endif  // _MULTIPLECHOICEQUESTION_H_
