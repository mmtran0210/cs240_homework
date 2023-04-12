// Minh My Tran - csce 240 - 003

#include "ShortAnswerQuestion.h"

namespace csce240_program5 {

ShortAnswerQuestion::ShortAnswerQuestion(string q, string a) : Question(q), answer_(a) {}

void ShortAnswerQuestion::SetAnswer(string a) {
  answer_ = a;
}

string ShortAnswerQuestion::GetAnswer() const {
  return answer_;
}

void ShortAnswerQuestion::Print(bool show_answer) const {
  Question::Print();
  if (show_answer)
    std::cout << "Correct Answer: " << answer_ << std::endl;
}

}  // namespace csce240_program5