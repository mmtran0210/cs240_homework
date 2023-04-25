// Minh My Tran - csce 240 - 003

#ifndef _SHORTANSWERQUESTION_H_
#define _SHORTANSWERQUESTION_H_

#include "question.h"
#include <string>

namespace csce240_program5 {

class ShortAnswerQuestion : public Question {
 public:
  explicit ShortAnswerQuestion(string q = "?", string a = "");
  virtual ~ShortAnswerQuestion() {}
  void SetAnswer(string a);
  string GetAnswer() const;
  virtual void Print(bool show_answer = false) const;
  virtual bool CheckAnswer(string answer) const;

 private:
  string answer_;
};

}  // namespace csce240_program5

#endif  // _SHORTANSWERQUESTION_H_