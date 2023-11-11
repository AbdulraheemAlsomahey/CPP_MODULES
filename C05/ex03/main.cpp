#include "Intern.hpp"

int main()
{
  std::string formName = "shrubbery creation"; 
  std::string formTarget = "Tree";
  Intern intern;
  Bureaucrat bureaucrat("abdo", 1);
  AForm *f = intern.makeForm(formName, formTarget);
  std::cout << *f;
  bureaucrat.signForm(*f);
  std::cout << (*f).getSigned() << std::endl;
  bureaucrat.executeForm(*f);
  delete f;
  return 0;
}
