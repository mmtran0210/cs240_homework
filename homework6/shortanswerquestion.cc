// Minh My Tran - csce 240 - 003

#include "shortanswerquestion.h"

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

bool ShortAnswerQuestion::CheckAnswer(string answer) const {
    if (answer == answer_)
        return true;
    else
        return false;
}

}  // namespace csce240_program5
