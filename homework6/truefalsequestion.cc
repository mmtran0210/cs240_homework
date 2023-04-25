// Minh My Tran - csce 240 - 003

#include "truefalsequestion.h"

namespace csce240_program5 {

TrueFalseQuestion::TrueFalseQuestion(string q, bool a) : Question(q) {
  answer_ = a;
}

void TrueFalseQuestion::SetAnswer(bool a) {
  answer_ = a;
}

bool TrueFalseQuestion::GetAnswer() const {
  return answer_;
}

void TrueFalseQuestion::Print(bool show_answer) const {
  Question::Print();
  if (show_answer)
    std::cout << "Correct Answer: " << (answer_ ? "true" : "false") << std::endl;
}

bool TrueFalseQuestion::CheckAnswer(string answer) const {
    if (answer == "true" && answer_ == true)
        return true;
    else if (answer == "false" && answer_ == false)
        return true;
    else
        return false;
}

}  // namespace csce240_program5