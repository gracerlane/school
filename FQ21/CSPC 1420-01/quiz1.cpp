// Grace Lane
// Quiz #1

struct Student
{
  string name;
  double gpa;
  date birthday;
};

int findName(const Student list[], int numStudents, string targetName);

int findName(const Student list[], int numStudents, string targetName)
{
  int index = 0;
  int targetIndex;
  while (index < numStudents && list[index].name != targetName) {
	index++;
  }
  if (index < numStudents) {
	targetIndex = index;
	return targetIndex;
  } else {
	return -1;
  }
}