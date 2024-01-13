#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Helper {
public:
	static char* GetStringFromBuffer(char*);
	static int stringLen(char*);
};
class EvaluationReport {
	friend void UpdateStatistics(EvaluationReport*);
private:
	char RollNo[9];
	char* Fname;
	char* Lname;
	int* QuizMarks;
	int* AssignmentMarks;
	int Total;
	static int* maxQuizzesMarks;
	static int* maxAssignmentsMarks;
	static int totalStudents;
	static int TotalQuizzes;
	static int TotalAssignments;
	static int* quizzesMin;
	static int* assignmentsMin;
	static int* quizzesMax;
	static int* assignmentsMax;
	static int* avg;
	static int matrixRows;
public:
	EvaluationReport();
	~EvaluationReport();
	EvaluationReport(const EvaluationReport&);
	const EvaluationReport& operator=(const EvaluationReport& rhs);
	void ReadDataFromFile(ifstream&);
	void printAll(EvaluationReport*);
	EvaluationReport** SearchStudentsByKeyWord(char*, EvaluationReport*);
	void PrintAll(EvaluationReport**);
	void SortListByTotal(EvaluationReport*);
	void setTotal(int);
	void DetailView(EvaluationReport*, char*);
	bool StudentFound(EvaluationReport*, char*);
	static void staticDeallocation();
	static void setTotalStudents(int);
	static void setTotalQuizzes(int);
	static void setTotalAssignments(int);
	static void setMatrixRows(int);
	static int getMatrixRows();
	static int getTotalStudents();
	static int getTotalQuizzes();
	static int getTotalAssignments();
	int getTotal();
	static void setMaxQuizzesMarks(int*);
	static void setMaxAssignmentMarks(int*);
	static int* getMaxQuizzesMarks();
	static int* getMaxAssignmentsMarks();
};
void display(EvaluationReport* stdList) {
	for (int i = 0; i < EvaluationReport::getTotalStudents(); i++) {
		stdList[i].printAll(stdList);
	}
}
int Helper::stringLen(char* cstr) {
	int count = 0;
	for (int i = 0; cstr[i] != '\0'; i++) {
		count++;
	}
	return count;
}
char* Helper::GetStringFromBuffer(char* buffer) {
	int strLen = Helper::stringLen(buffer);
	char* str = 0;

	if (strLen > 0)
	{
		str = new char[strLen + 1];
		char* tempDest = str;
		for (char* tempSrc = buffer; *tempSrc != '\0'; tempSrc++, tempDest++)
		{
			*tempDest = *tempSrc;
		}
		*tempDest = '\0';
	}
	return str;
}
//int* EvaluationReport::maxQuizzesMarks = 0;
//int* EvaluationReport::maxAssignmentsMarks = 0;
EvaluationReport::EvaluationReport() { }
EvaluationReport::EvaluationReport(const EvaluationReport& rhs) {
	if (&rhs != this)
	{
		Fname = 0;
		Lname = 0;
		QuizMarks = 0;
		AssignmentMarks = 0;

		int temp = 0;
		for (int i = 0; i < 8; i++)
		{
			RollNo[i] = rhs.RollNo[i];
		}
		temp = Helper::stringLen(rhs.Fname);
		Fname = new char[temp + 1];
		for (int i = 0; i < temp; i++)
		{
			Fname[i] = rhs.Fname[i];
		}
		Fname[temp] = '\0';
		temp = Helper::stringLen(rhs.Lname);
		Lname = new char[temp + 1];
		for (int i = 0; i < temp; i++)
		{
			Lname[i] = rhs.Lname[i];
		}
		Lname[temp] = '\0';
		temp = TotalQuizzes;
		QuizMarks = new int[temp];
		for (int i = 0; i < temp; i++)
		{
			QuizMarks[i] = rhs.QuizMarks[i];
		}
		temp = TotalAssignments;
		AssignmentMarks = new int[temp];
		for (int i = 0; i < temp; i++)
		{
			AssignmentMarks[i] = rhs.AssignmentMarks[i];
		}
		Total = rhs.Total;
	}
}
const EvaluationReport& EvaluationReport::operator=(const EvaluationReport& rhs) {
	
		if (&rhs != this)
		{
			Fname = 0;
			Lname = 0;
			QuizMarks = 0;
			AssignmentMarks = 0;

			int temp = 0;
			for (int i = 0; i < 8; i++)
			{
				RollNo[i] = rhs.RollNo[i];
			}
			temp = Helper::stringLen(rhs.Fname);
			Fname = new char[temp + 1];
			for (int i = 0; i < temp; i++)
			{
				Fname[i] = rhs.Fname[i];
			}
			Fname[temp] = '\0';
			temp = Helper::stringLen(rhs.Lname);
			Lname = new char[temp + 1];
			for (int i = 0; i < temp; i++)
			{
				Lname[i] = rhs.Lname[i];
			}
			Lname[temp] = '\0';
			temp = TotalQuizzes;
			QuizMarks = new int[temp];
			for (int i = 0; i < temp; i++)
			{
				QuizMarks[i] = rhs.QuizMarks[i];
			}
			temp = TotalAssignments;
			AssignmentMarks = new int[temp];
			for (int i = 0; i < temp; i++)
			{
				AssignmentMarks[i] = rhs.AssignmentMarks[i];
			}
			Total = rhs.Total;
		}
		return *this;
	

}
EvaluationReport::~EvaluationReport() {
	if (Fname != 0) {
		delete[] Fname;
		Fname = 0;
	}
	if (Lname != 0) {
		delete[] Lname;
		Lname = 0;
	}
	if (QuizMarks != 0) {
		delete[] QuizMarks;
		QuizMarks = 0;
	}
	if (AssignmentMarks != 0) {
		delete[] AssignmentMarks;
		AssignmentMarks = 0;
	}
}
void EvaluationReport::staticDeallocation() {
	delete[] maxQuizzesMarks;
	maxQuizzesMarks = 0;
	delete[] maxAssignmentsMarks;
	maxAssignmentsMarks = 0;
	delete[] quizzesMin;
	quizzesMin = 0;
	delete[] quizzesMax;
	quizzesMax = 0;
	delete[] assignmentsMax;
	assignmentsMax = 0;
	delete[] assignmentsMin;
	assignmentsMin = 0;
	delete[] avg;
	avg = 0;
}
int* EvaluationReport::quizzesMin = 0;
int* EvaluationReport::assignmentsMin = 0;
int* EvaluationReport::quizzesMax = 0;
int* EvaluationReport::assignmentsMax = 0;
int* EvaluationReport::avg = 0;
int EvaluationReport::matrixRows = 0;
void EvaluationReport::setTotal(int total) {
	Total = total;
}
void EvaluationReport::setTotalStudents(int Tstu) {
	totalStudents = Tstu;
}
void EvaluationReport::setTotalQuizzes(int Tstu) {
	TotalQuizzes = Tstu;
}
void EvaluationReport::setTotalAssignments(int Tstu) {
	TotalAssignments = Tstu;
}
int EvaluationReport::getTotal() {
	return Total;
}
int EvaluationReport::getTotalStudents() {
	return totalStudents;
}
int EvaluationReport::getTotalQuizzes() {
	return TotalQuizzes;
}
int EvaluationReport::getTotalAssignments() {
	return TotalAssignments;
}
void EvaluationReport::setMaxQuizzesMarks(int* maxQuiz) {
	maxQuizzesMarks = maxQuiz;
}
void EvaluationReport::setMaxAssignmentMarks(int* maxAssignment) {
	maxAssignmentsMarks = maxAssignment;
}
int* EvaluationReport::getMaxQuizzesMarks() {
	return maxQuizzesMarks;
}
int* EvaluationReport::getMaxAssignmentsMarks() {
	return maxAssignmentsMarks;
}
void EvaluationReport::setMatrixRows(int size) {
	matrixRows = size;
}
int EvaluationReport::getMatrixRows() {
	return matrixRows;
}
void EvaluationReport::ReadDataFromFile(ifstream& fin) {
	fin >> RollNo;
	char name[50];
	fin >> name;
	Fname = Helper::GetStringFromBuffer(name);
	fin >> name;
	Lname = Helper::GetStringFromBuffer(name);
	QuizMarks = new int[TotalQuizzes + 1];
	for (int i = 0; i < TotalQuizzes; i++) {
		fin >> QuizMarks[i];
	}
	QuizMarks[TotalQuizzes] = '\0';
	AssignmentMarks = new int[TotalAssignments + 1];
	for (int i = 0; i < TotalAssignments; i++) {
		fin >> AssignmentMarks[i];
	}
	QuizMarks[TotalAssignments] = '\0';
}
static EvaluationReport* ReadStaticDataFromFile(ifstream& fin) {
	int sts, stQs, stAs;
	int* maxQuizzesMarks = 0, * maxAssignmentsMarks = 0;
	fin >> sts;
	fin >> stQs;
	fin >> stAs;
	EvaluationReport::setTotalStudents(sts);
	EvaluationReport::setTotalQuizzes(stQs);
	EvaluationReport::setTotalAssignments(stAs);
	maxQuizzesMarks = new int[stQs + 1];
	maxAssignmentsMarks = new int[stAs + 1];
	for (int* ptr = maxQuizzesMarks; ptr < stQs + maxQuizzesMarks; ptr++) {
		fin >> *ptr;

	}
	maxQuizzesMarks[stQs] = '\0';
	for (int* ptr = maxAssignmentsMarks; ptr < maxAssignmentsMarks + stAs; ptr++) {
		fin >> *ptr;
	}
	maxAssignmentsMarks[stAs] = '\0';
	EvaluationReport::setMaxQuizzesMarks(maxQuizzesMarks);
	EvaluationReport::setMaxAssignmentMarks(maxAssignmentsMarks);
	EvaluationReport* StudentsTable = new EvaluationReport[EvaluationReport::getTotalStudents()];
	for (int i = 0; i < EvaluationReport::getTotalStudents(); i++) {
		StudentsTable[i].ReadDataFromFile(fin);
	}
	return StudentsTable;
}
int EvaluationReport::totalStudents = EvaluationReport::getTotalStudents();
int EvaluationReport::TotalQuizzes = EvaluationReport::getTotalQuizzes();
int EvaluationReport::TotalAssignments = EvaluationReport::getTotalAssignments();
int* EvaluationReport::maxQuizzesMarks = EvaluationReport::getMaxQuizzesMarks();
int* EvaluationReport::maxAssignmentsMarks = EvaluationReport::getMaxAssignmentsMarks();
void UpdateStatistics(EvaluationReport* StudentsTable) {
	int min, max;
	EvaluationReport::quizzesMin = new int[EvaluationReport::TotalQuizzes + 1];
	for (int i = 0; i < EvaluationReport::TotalQuizzes; i++) {
		min = StudentsTable[0].QuizMarks[i];
		for (int j = 0; j < EvaluationReport::totalStudents - 1; j++) {
			if (StudentsTable[j].QuizMarks[i] < min) {
				min = StudentsTable[j].QuizMarks[i];
			}
		}
		EvaluationReport::quizzesMin[i] = min;
	}
	EvaluationReport::quizzesMin[EvaluationReport::TotalQuizzes] = '\0';
	EvaluationReport::quizzesMax = new int[EvaluationReport::TotalQuizzes + 1];
	for (int i = 0; i < EvaluationReport::TotalQuizzes; i++) {
		max = StudentsTable[0].QuizMarks[i];
		for (int j = 0; j < EvaluationReport::totalStudents; j++) {
			if (StudentsTable[j].QuizMarks[i] > max) {
				max = StudentsTable[j].QuizMarks[i];
			}
		}
		EvaluationReport::quizzesMax[i] = max;
	}
	EvaluationReport::quizzesMax[EvaluationReport::TotalQuizzes] = '\0';
	EvaluationReport::assignmentsMin = new int[EvaluationReport::TotalAssignments + 1];
	for (int i = 0, j = 0; i < EvaluationReport::TotalAssignments; i++) {
		min = StudentsTable[0].AssignmentMarks[i];
		for (int j = 0; j < EvaluationReport::totalStudents; j++) {
			if (StudentsTable[j].AssignmentMarks[i] < min) {
				min = StudentsTable[j].AssignmentMarks[i];
			}
		}
		EvaluationReport::assignmentsMin[i] = min;
	}
	EvaluationReport::assignmentsMin[EvaluationReport::TotalAssignments] = '\0';
	EvaluationReport::assignmentsMax = new int[EvaluationReport::TotalAssignments + 1];
	for (int i = 0, j = 0; i < EvaluationReport::TotalAssignments; i++) {
		max = StudentsTable[0].AssignmentMarks[i];
		for (int j = 0; j < EvaluationReport::totalStudents; j++) {
			if (StudentsTable[j].AssignmentMarks[i] > max) {
				max = StudentsTable[j].AssignmentMarks[i];
			}
		}
		EvaluationReport::assignmentsMax[i] = max;
	}
	EvaluationReport::assignmentsMax[EvaluationReport::TotalAssignments] = '\0';
	int total;
	EvaluationReport::avg = new int[EvaluationReport::TotalQuizzes + EvaluationReport::TotalAssignments + 1];
	for (int i = 0; i < EvaluationReport::TotalQuizzes; i++) {
		total = 0;
		for (int j = 0; j < EvaluationReport::totalStudents; j++) {
			total += StudentsTable[j].QuizMarks[i];
		}
		EvaluationReport::avg[i] = total / EvaluationReport::totalStudents;
	}
	int index = EvaluationReport::TotalQuizzes;
	for (int i = 0; i < EvaluationReport::TotalAssignments; i++) {
		total = 0;
		for (int j = 0; j < EvaluationReport::totalStudents; j++) {
			total += StudentsTable[j].AssignmentMarks[i];
		}
		EvaluationReport::avg[index] = total / EvaluationReport::totalStudents;
		index++;
	}
	EvaluationReport::avg[EvaluationReport::TotalAssignments + EvaluationReport::TotalQuizzes] = '\0';
	cout << "         Q1  Q2  Q3  Q4  A1  A2  A3  A4" << endl;
	cout << "Total:   ";
	for (int i = 0; i < EvaluationReport::TotalQuizzes; i++) {
		cout << EvaluationReport::maxQuizzesMarks[i] << "  ";
	}
	for (int i = 0; i < EvaluationReport::TotalAssignments; i++) {
		cout << EvaluationReport::maxAssignmentsMarks[i] << "  ";
	}
	cout << endl;
	cout << "Maximum: ";
	for (int i = 0; i < EvaluationReport::TotalQuizzes; i++) {
		cout << EvaluationReport::quizzesMax[i] << "  ";
	}
	for (int i = 0; i < EvaluationReport::TotalAssignments; i++) {
		cout << EvaluationReport::assignmentsMax[i] << "  ";
	}
	cout << endl;
	cout << "Minimum:  ";
	for (int i = 0; i < EvaluationReport::TotalQuizzes; i++) {
		cout << EvaluationReport::quizzesMin[i] << "   ";
	}
	for (int i = 0; i < EvaluationReport::TotalAssignments; i++) {
		cout << EvaluationReport::assignmentsMin[i] << "   ";
	}
	cout << endl;
	cout << "Average:  ";
	for (int i = 0; i < EvaluationReport::TotalQuizzes + EvaluationReport::TotalAssignments; i++) {
		cout << EvaluationReport::avg[i] << "   ";
	}
	cout << endl;
}
void EvaluationReport::printAll(EvaluationReport* stdList) {
		cout << RollNo << "   " << Fname << " " << Lname << "   ";
		for (int z = 0; z < TotalQuizzes; z++) {
			cout <<QuizMarks[z] << "   ";
		}
		for (int z = 0; z < TotalAssignments; z++) {
			cout << AssignmentMarks[z] << "   ";
		}
		int sum = 0;
		for (int j = 0; j < TotalQuizzes; j++) {
			sum += QuizMarks[j];
		}
		for (int k = 0; k < TotalAssignments; k++) {
			sum += AssignmentMarks[k];
		}
		this->Total = sum;
		cout << "  " << this->Total;
		setTotal(sum);
		cout << endl;
}
EvaluationReport** EvaluationReport::SearchStudentsByKeyWord(char* cstring, EvaluationReport* stdList) {
	for (int i = 0; i < totalStudents; i++) {
		if (stdList[i].RollNo == cstring) {
			matrixRows++;
		}
		else if (stdList[i].Fname == cstring) {
			matrixRows++;
		}
		else if (stdList[i].Lname == cstring) {
			matrixRows++;
		}
		else {
			int isEqual = 0;
			int y = 0;
			int k = 0;
			while (y <= Helper::stringLen(stdList[i].RollNo)) {
				if (stdList[i].RollNo[y] == cstring[k]) {
					for (int x = y, z = 0; x < Helper::stringLen(stdList[i].RollNo); x++, z++) {
						if (stdList[i].RollNo[x] == cstring[z]) {
							isEqual++;
						}
					}
					if (isEqual == Helper::stringLen(cstring)) {
						matrixRows++;
						break;
					}
					else {
						isEqual = 0;
					}
				    k++;
				}
				y++;
			}
			if (isEqual == Helper::stringLen(cstring)) {}
			else {
				isEqual = 0;
				y = 0;
				k = 0;
				while (y <= Helper::stringLen(stdList[i].Fname)) {
					if (stdList[i].Fname[y] == cstring[k]) {
						for (int x = y, z = 0; x < Helper::stringLen(stdList[i].Fname); x++, z++) {
							if (stdList[i].Fname[x] == cstring[z]) {
								isEqual++;
							}
						}
						if (isEqual == Helper::stringLen(cstring)) {
							matrixRows++;
							break;
						}
						else {
							isEqual = 0;
						}
						k++;
						
					}
					y++;
				}
				if (isEqual == Helper::stringLen(cstring)) {
				}
				else {
					isEqual = 0;
					y = 0;
					k = 0;
					while (y <= Helper::stringLen(stdList[i].Lname)) {
						if (stdList[i].Lname[y] == cstring[k]) {
							for (int x = y, z = 0; x < Helper::stringLen(stdList[i].Lname); x++, z++) {
								if (stdList[i].Lname[x] == cstring[z]) {
									isEqual++;
								}
							}
							if (isEqual == Helper::stringLen(cstring)) {
								matrixRows++;
								break;
							}
							else {
								isEqual = 0;
							}
							k++;
							
						}
						y++;
					}
				}
			}
		}

	}
	int temp;
	temp = EvaluationReport::getMatrixRows();
	cout << temp << endl;
	EvaluationReport** matrix = new EvaluationReport * [matrixRows];
	int index = 0;
	for (int i = 0; i < totalStudents; i++) {
		if (stdList[i].RollNo == cstring) {
			matrix[index] = &stdList[i];
			index++;
		}
		else if (stdList[i].Fname == cstring) {
			matrix[index] = &stdList[i];
			index++;
		}
		else if (stdList[i].Lname == cstring) {
			matrix[index] = &stdList[i];
			index++;
		}
		else {
			int isEqual = 0;
			int y = 0;
			int k = 0;
			while (y <= Helper::stringLen(stdList[i].RollNo)) {
				if (stdList[i].RollNo[y] == cstring[k]) {
					for (int x = y, z = 0; x < Helper::stringLen(stdList[i].RollNo); x++, z++) {
						if (stdList[i].RollNo[x] == cstring[z]) {
							isEqual++;
						}
					}
					if (isEqual == Helper::stringLen(cstring)) {
						matrix[index] = &stdList[i];
						index++;
						break;
					}
					else {
						isEqual = 0;
					}
					k++;
				}
				y++;
			}
			if (isEqual == Helper::stringLen(cstring)) {
			}
			else {
				isEqual = 0;
				y = 0;
				k = 0;
				while (y <= Helper::stringLen(stdList[i].Fname)) {
					if (stdList[i].Fname[y] == cstring[k]) {
						for (int x = y, z = 0; x < Helper::stringLen(stdList[i].Fname); x++, z++) {
							if (stdList[i].Fname[x] == cstring[z]) {
								isEqual++;
							}
						}
						if (isEqual == Helper::stringLen(cstring)) {
							matrix[index] = &stdList[i];
							index++;
							break;
						}
						else {
							isEqual = 0;
						}
						k++;
					}
					y++;
				}
				if (isEqual == Helper::stringLen(cstring)) {
				}
				else {
					isEqual = 0;
					y = 0;
					k = 0;
					while (y <= Helper::stringLen(stdList[i].Lname)) {
						if (stdList[i].Lname[y] == cstring[k]) {
							for (int x = y, z = 0; x < Helper::stringLen(stdList[i].Lname); x++, z++) {
								if (stdList[i].Lname[x] == cstring[z]) {
									isEqual++;
								}
							}
							if (isEqual == Helper::stringLen(cstring)) {
								matrix[index] = &stdList[i];
								index++;
								break;
							}
							else {
								isEqual = 0;
							}
							k++;
						}
						y++;
					}
					
				}
			}
		}
	}
	return matrix;
}
void EvaluationReport::PrintAll(EvaluationReport** matrix) {
	for (int i = 0; i < matrixRows; i++) {
		cout << matrix[i]->RollNo << "   " << matrix[i]->Fname << "  " << matrix[i]->Lname << "   ";
		for (int z = 0; z < TotalQuizzes; z++) {
			cout << matrix[i]->QuizMarks[z] << "   ";
		}
		for (int l = 0; l < TotalAssignments; l++) {
			cout << matrix[i]->AssignmentMarks[l] << "   ";
		}
		cout << matrix[i]->Total;
		cout << endl;
	}
}
void EvaluationReport::SortListByTotal(EvaluationReport* stdList) {
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < totalStudents; i++)
	{
		for (int j = i + 1; j < totalStudents; j++)
		{
			temp1 = stdList[i].getTotal();

			temp2 = stdList[j].getTotal();

			if (temp2 > temp1)
			{
				EvaluationReport temp;
				temp = stdList[i];
				stdList[i] = stdList[j];
				stdList[j] = temp;
			}
		}
	}
	
}
bool EvaluationReport::StudentFound(EvaluationReport* stdList, char* rollNo) {
	bool found = false;
	int count = 0;
	for (int i = 0; i < totalStudents; i++) {
		count = 0;
		for (int z = 0; z < 8; z++) {
			if (stdList[i].RollNo[z] == rollNo[z]) {
				count++;
			}
		}
		if (count == 8) {
			return true;
		}
	}
	return found;
}

void EvaluationReport::DetailView(EvaluationReport* stdList, char* rollNo) {
	int count = 0;
	for (int i = 0; i < totalStudents; i++) {
		count = 0;
		for (int z = 0; z < 8; z++) {
			if (stdList[i].RollNo[z] == rollNo[z]) {
				count++;
			}
		}
		if (count == 8) {
			cout << "Roll No:   " << stdList[i].RollNo << endl;
			cout << "Name:   " << stdList[i].Fname<<" ";
			cout << stdList[i].Lname << endl;
			cout << "Quizzes Marks:   " << endl;
			for (int k = 0; k < TotalQuizzes; k++) {
				cout << "Q"<<k + 1<<":  " << stdList[i].QuizMarks[k]<<"/"<<quizzesMax[k] << endl;;
			}
			cout << "Assignment Marks:   " << endl;
			for (int k = 0; k < TotalAssignments; k++) {
				cout << "A"<<k + 1<<":  " << stdList[i].AssignmentMarks[k]<<"/"<<assignmentsMax[k] << endl;;
			}
		}
	}
}
int main()
{
	ifstream fin;
	fin.open("gradesheet.txt");
	EvaluationReport* Eptr = 0;
	EvaluationReport** eptr = 0;
	Eptr = ReadStaticDataFromFile(fin);
	EvaluationReport Flex;
	UpdateStatistics(Eptr);
	display(Eptr);
	cout << endl << endl << endl;
	char* cstring = 0;
	char string[20];
	cout << "Enter a string to search in report: ";
	cin.getline(string, 15);
	cstring = Helper::GetStringFromBuffer(string);
	eptr = Flex.SearchStudentsByKeyWord(cstring, Eptr);
	Flex.PrintAll(eptr);
	Flex.SortListByTotal(Eptr);
	cout << endl << endl;
	cout << "Sorted Record: \n" << endl;
	display(Eptr);
	char Temp2[9] = "15L-1234";
	Flex.StudentFound(Eptr, Temp2);
	if (Flex.StudentFound(Eptr, Temp2) == 1) {
		cout << endl;
		Flex.DetailView(Eptr, Temp2);
	}
	else {
		cout << endl;
		
		cout << "For Roll No "<< Temp2 << endl;
		cout << "Student Not Found" << endl;
	}
	char Temp[9] = "15L-4023";
	Flex.StudentFound(Eptr, Temp);
	if (Flex.StudentFound(Eptr, Temp) == 1) {
		cout << endl;
		Flex.DetailView(Eptr, Temp);
	}
	else {
		cout << endl;
		
		cout << "For Roll No " << Temp << endl;
		cout << "Student Not Found" << endl;
	}
	Flex.staticDeallocation();
	delete[] Eptr;
	Eptr = 0;
	delete[] cstring;
	cstring = 0;
	if (eptr != 0) {
	delete[] eptr;
	}
	return 0;
}