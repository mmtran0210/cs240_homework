// Minh My Tran - csce 240 - 003

#ifndef _SHORTANSWERQUESTION_H_
#define _SHORTANSWERQUESTION_H_

#include "Question.h"
#include <string>

namespace csce240_program5 {

class ShortAnswerQuestion : public Question {
 public:
  explicit ShortAnswerQuestion(string q = "?", string a = "");
  void SetAnswer(string a);
  string GetAnswer() const;
  void Print(bool show_answer = false) const;
 private:
  string answer_;
};

}  // namespace csce240_program5

#endif  // _SHORTANSWERQUESTION_H_