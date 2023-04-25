// Minh My Tran - csce 240 - 003

#ifndef _TRUE_FALSE_QUESTION_H_
#define _TRUE_FALSE_QUESTION_H_

#include "question.h"

namespace csce240_program5 {

class TrueFalseQuestion : public Question {
 public:
  explicit TrueFalseQuestion(string q = "?", bool a = true);
  virtual ~TrueFalseQuestion() {}
  void SetAnswer(bool a);
  bool GetAnswer() const;
  virtual void Print(bool show_answer) const;
  virtual bool CheckAnswer(string answer) const;

 private:
  bool answer_;
};

}  // namespace csce240_program5

#endif  // _TRUE_FALSE_QUESTION_H_