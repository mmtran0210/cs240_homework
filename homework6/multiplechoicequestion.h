// Minh My Tran - csce 240 - 003


#ifndef _MULTIPLECHOICEQUESTION_H_
#define _MULTIPLECHOICEQUESTION_H_

#include "question.h"
#include <string>

namespace csce240_program5 {

class MultipleChoiceQuestion : public Question {
 public:
  explicit MultipleChoiceQuestion(string q = "?", int n = 0, string *choices = nullptr, bool *correct = nullptr);
  MultipleChoiceQuestion(const MultipleChoiceQuestion &other);
  MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion &other);
  virtual ~MultipleChoiceQuestion();
  void SetNumChoices(int n);
  int GetNumChoices() const;
  void SetChoices(string *choices);
  string* GetChoices() const;
  void SetCorrect(bool *correct);
  bool* GetCorrect() const;
  virtual void Print(bool show_answer = false) const;
  void SetAnswerChoices(int n, string *choices, bool *correct);
  virtual bool CheckAnswer(string answer) const;
 private:
  int num_choices_;
  string *choices_;
  bool *correct_;
};

}  // namespace csce240_program5

#endif  // _MULTIPLECHOICEQUESTION_H_

