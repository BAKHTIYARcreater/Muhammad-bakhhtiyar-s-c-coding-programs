/*
 ===========================================================================
   HOSPITAL MANAGEMENT SYSTEM  -  Data Structures & Algorithms Project
   Language : C++ (works in Dev-C++, no C++11 features used)
   Level    : BSCS 2nd Year

   DATA STRUCTURES USED (and WHY)
   ---------------------------------------------------------------------------
   1. Binary Search Tree (BST)  -> Patient records, key = Patient ID
        Insert / Search / Delete : O(log n) average
        Inorder traversal        : gives patients sorted by ID automatically
   2. Singly Linked List        -> Doctors list (dynamic, no size limit)
   3. Queue (linked, FIFO)      -> Normal OPD appointments (first come, first served)
   4. Max-Heap (Priority Queue) -> Emergency patients (most severe treated first)
        Insert / Extract         : O(log n)
   5. Stack (linked, LIFO)      -> Discharge history + UNDO last discharge
   6. Arrays + Sorting          -> Insertion Sort (by name), Selection Sort (by age)
   7. File Handling             -> Data saved/loaded from text files
                                   (BST saved in PREORDER so its shape is
                                    rebuilt exactly when loaded)
 ===========================================================================
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
using namespace std;

const int ROOM_CHARGE_PER_DAY = 2000;      // Rs. per day in ward
const int MAX_EMERGENCY       = 100;       // heap capacity
const char* PATIENT_FILE      = "patients.txt";
const char* DOCTOR_FILE       = "doctors.txt";

// ===========================================================================
//                           HELPER (UTILITY) FUNCTIONS
// ===========================================================================
string toLower(string s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] = (char)tolower(s[i]);
    return s;
}

void clearScreen()
{
    system("cls");          // Windows (Dev-C++). Use "clear" on Linux.
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    string t;
    getline(cin, t);
}

// Reads a non-empty line of text ('|' is replaced because it is the file separator)
string readText(const string& prompt)
{
    string s;
    while (true)
    {
        cout << prompt;
        getline(cin, s);
        for (size_t i = 0; i < s.size(); i++)
            if (s[i] == '|') s[i] = ' ';
        if (!s.empty()) return s;
        cout << "  Input cannot be empty!\n";
    }
}

// Reads an integer between lo and hi (keeps asking until the input is valid)
int readInt(const string& prompt, int lo, int hi)
{
    string s;
    while (true)
    {
        cout << prompt;
        getline(cin, s);
        bool ok = (!s.empty() && s.size() <= 9);
        for (size_t i = 0; i < s.size(); i++)
            if (!isdigit((unsigned char)s[i])) ok = false;
        if (ok)
        {
            int v = atoi(s.c_str());
            if (v >= lo && v <= hi) return v;
        }
        cout << "  Invalid! Enter a number between " << lo << " and " << hi << ".\n";
    }
}

// ===========================================================================
//                    1. PATIENT  ->  BINARY SEARCH TREE
// ===========================================================================
struct Patient
{
    int     id;
    string  name;
    int     age;
    string  gender;
    string  disease;
    int     doctorId;
    int     days;               // days admitted
    Patient *left, *right;

    Patient(int i, string n, int a, string g, string d, int doc, int dy)
    {
        id = i; name = n; age = a; gender = g;
        disease = d; doctorId = doc; days = dy;
        left = right = NULL;
    }
};

void printPatientHeader()
{
    cout << left << setw(7) << "ID" << setw(20) << "Name" << setw(5) << "Age"
         << setw(9) << "Gender" << setw(18) << "Disease"
         << setw(8) << "DocID" << setw(6) << "Days" << endl;
    cout << string(73, '-') << endl;
}

void printPatientRow(Patient* p)
{
    cout << left << setw(7) << p->id << setw(20) << p->name.substr(0, 19)
         << setw(5) << p->age << setw(9) << p->gender
         << setw(18) << p->disease.substr(0, 17)
         << setw(8) << p->doctorId << setw(6) << p->days << endl;
}

class PatientBST
{
private:
    Patient* root;
    int      count;

    // ---- recursive helpers ----
    Patient* insertRec(Patient* node, Patient* p, bool& done)
    {
        if (node == NULL) { done = true; return p; }
        if (p->id < node->id)       node->left  = insertRec(node->left,  p, done);
        else if (p->id > node->id)  node->right = insertRec(node->right, p, done);
        // equal id -> duplicate, done stays false
        return node;
    }

    Patient* searchRec(Patient* node, int id)
    {
        if (node == NULL || node->id == id) return node;
        if (id < node->id) return searchRec(node->left, id);
        return searchRec(node->right, id);
    }

    void copyData(Patient* to, Patient* from)
    {
        to->id = from->id;           to->name = from->name;
        to->age = from->age;         to->gender = from->gender;
        to->disease = from->disease; to->doctorId = from->doctorId;
        to->days = from->days;
    }

    // Delete has 3 cases: leaf, one child, two children
    Patient* removeRec(Patient* node, int id, bool& found)
    {
        if (node == NULL) return NULL;
        if (id < node->id)       node->left  = removeRec(node->left,  id, found);
        else if (id > node->id)  node->right = removeRec(node->right, id, found);
        else
        {
            found = true;
            if (node->left == NULL)             // case 1 & 2: no left child
            {
                Patient* r = node->right;
                delete node;
                return r;
            }
            if (node->right == NULL)            // case 2: no right child
            {
                Patient* l = node->left;
                delete node;
                return l;
            }
            // case 3: two children -> replace with inorder successor
            Patient* succ = node->right;
            while (succ->left != NULL) succ = succ->left;
            copyData(node, succ);
            bool dummy = false;
            node->right = removeRec(node->right, succ->id, dummy);
        }
        return node;
    }

    void inorderPrint(Patient* node)
    {
        if (node == NULL) return;
        inorderPrint(node->left);
        printPatientRow(node);
        inorderPrint(node->right);
    }

    void inorderToArray(Patient* node, Patient** arr, int& idx)
    {
        if (node == NULL) return;
        inorderToArray(node->left, arr, idx);
        arr[idx++] = node;
        inorderToArray(node->right, arr, idx);
    }

    void nameSearchRec(Patient* node, const string& key, int& found)
    {
        if (node == NULL) return;
        if (toLower(node->name).find(key) != string::npos)
        {
            if (found == 0) printPatientHeader();
            printPatientRow(node);
            found++;
        }
        nameSearchRec(node->left, key, found);
        nameSearchRec(node->right, key, found);
    }

    void saveRec(Patient* node, ofstream& f)    // PREORDER keeps tree shape
    {
        if (node == NULL) return;
        f << node->id << '|' << node->name << '|' << node->age << '|'
          << node->gender << '|' << node->disease << '|'
          << node->doctorId << '|' << node->days << '\n';
        saveRec(node->left, f);
        saveRec(node->right, f);
    }

    void destroy(Patient* node)
    {
        if (node == NULL) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    PatientBST() { root = NULL; count = 0; }
    ~PatientBST() { destroy(root); }

    int size() { return count; }

    bool insert(Patient* p)
    {
        bool done = false;
        root = insertRec(root, p, done);
        if (done) count++;
        return done;
    }

    Patient* search(int id) { return searchRec(root, id); }

    bool remove(int id)
    {
        bool found = false;
        root = removeRec(root, id, found);
        if (found) count--;
        return found;
    }

    void displayAll()
    {
        if (root == NULL) { cout << "  No patients registered.\n"; return; }
        printPatientHeader();
        inorderPrint(root);
    }

    int searchByName(const string& name)
    {
        int found = 0;
        nameSearchRec(root, toLower(name), found);
        return found;
    }

    // Copies all patient pointers (in ID order) into a new array. Caller must delete[].
    Patient** toArray(int& n)
    {
        n = count;
        if (n == 0) return NULL;
        Patient** arr = new Patient*[n];
        int idx = 0;
        inorderToArray(root, arr, idx);
        return arr;
    }

    void saveToFile(const char* filename)
    {
        ofstream f(filename);
        if (!f) { cout << "  Could not open " << filename << " for writing.\n"; return; }
        saveRec(root, f);
        f.close();
    }
};

// ===========================================================================
//                    2. DOCTORS  ->  SINGLY LINKED LIST
// ===========================================================================
struct Doctor
{
    int     id;
    string  name;
    string  specialization;
    int     fee;
    int     patientsTreated;
    Doctor* next;
};

class DoctorList
{
private:
    Doctor* head;
    Doctor* tail;
    int     count;
public:
    DoctorList() { head = tail = NULL; count = 0; }
    ~DoctorList()
    {
        while (head != NULL) { Doctor* t = head; head = head->next; delete t; }
    }

    int size() { return count; }

    void add(int id, string name, string spec, int fee, int treated)
    {
        Doctor* d = new Doctor;
        d->id = id; d->name = name; d->specialization = spec;
        d->fee = fee; d->patientsTreated = treated; d->next = NULL;
        if (head == NULL) head = tail = d;      // insert at end : O(1) using tail
        else { tail->next = d; tail = d; }
        count++;
    }

    Doctor* find(int id)                        // linear search : O(n)
    {
        Doctor* cur = head;
        while (cur != NULL && cur->id != id) cur = cur->next;
        return cur;
    }

    bool remove(int id)
    {
        Doctor *cur = head, *prev = NULL;
        while (cur != NULL && cur->id != id) { prev = cur; cur = cur->next; }
        if (cur == NULL) return false;
        if (prev == NULL) head = cur->next;
        else prev->next = cur->next;
        if (cur == tail) tail = prev;
        delete cur;
        count--;
        return true;
    }

    void display(const string& specFilter = "")
    {
        int shown = 0;
        string key = toLower(specFilter);
        for (Doctor* d = head; d != NULL; d = d->next)
        {
            if (!key.empty() && toLower(d->specialization).find(key) == string::npos)
                continue;
            if (shown == 0)
            {
                cout << left << setw(6) << "ID" << setw(20) << "Name"
                     << setw(18) << "Specialization" << setw(8) << "Fee"
                     << setw(8) << "Treated" << endl;
                cout << string(60, '-') << endl;
            }
            cout << left << setw(6) << d->id << setw(20) << d->name.substr(0, 19)
                 << setw(18) << d->specialization.substr(0, 17) << setw(8) << d->fee
                 << setw(8) << d->patientsTreated << endl;
            shown++;
        }
        if (shown == 0) cout << "  No doctors found.\n";
    }

    int maxId()
    {
        int m = 0;
        for (Doctor* d = head; d != NULL; d = d->next)
            if (d->id > m) m = d->id;
        return m;
    }

    void saveToFile(const char* filename)
    {
        ofstream f(filename);
        if (!f) { cout << "  Could not open " << filename << " for writing.\n"; return; }
        for (Doctor* d = head; d != NULL; d = d->next)
            f << d->id << '|' << d->name << '|' << d->specialization << '|'
              << d->fee << '|' << d->patientsTreated << '\n';
        f.close();
    }
};

// ===========================================================================
//                  3. OPD APPOINTMENTS  ->  QUEUE (FIFO)
// ===========================================================================
struct Appointment
{
    int          patientId;
    int          doctorId;
    Appointment* next;
};

class AppointmentQueue
{
private:
    Appointment *front, *rear;
    int count;
public:
    AppointmentQueue() { front = rear = NULL; count = 0; }
    ~AppointmentQueue()
    {
        while (front != NULL) { Appointment* t = front; front = front->next; delete t; }
    }

    int size() { return count; }
    bool isEmpty() { return front == NULL; }

    void enqueue(int pid, int did)              // add at rear : O(1)
    {
        Appointment* a = new Appointment;
        a->patientId = pid; a->doctorId = did; a->next = NULL;
        if (rear == NULL) front = rear = a;
        else { rear->next = a; rear = a; }
        count++;
    }

    bool dequeue(int& pid, int& did)            // remove from front : O(1)
    {
        if (front == NULL) return false;
        Appointment* t = front;
        pid = t->patientId; did = t->doctorId;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete t;
        count--;
        return true;
    }

    void display()
    {
        if (front == NULL) { cout << "  No pending appointments.\n"; return; }
        cout << left << setw(8) << "Token" << setw(12) << "PatientID" << setw(10) << "DoctorID" << endl;
        cout << string(30, '-') << endl;
        int token = 1;
        for (Appointment* a = front; a != NULL; a = a->next)
            cout << left << setw(8) << token++ << setw(12) << a->patientId
                 << setw(10) << a->doctorId << endl;
    }
};

// ===========================================================================
//            4. EMERGENCY  ->  MAX-HEAP (PRIORITY QUEUE, array based)
// ===========================================================================
struct Emergency
{
    int patientId;
    int severity;       // 1 (minor) ... 5 (critical)
    int order;          // arrival order, used to break ties (FIFO among equals)
};

class EmergencyHeap
{
private:
    Emergency data[MAX_EMERGENCY];
    int  size_;
    int  arrivalCounter;

    // true if a should be treated BEFORE b
    bool higher(const Emergency& a, const Emergency& b)
    {
        if (a.severity != b.severity) return a.severity > b.severity;
        return a.order < b.order;
    }

    void heapifyUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (higher(data[i], data[parent]))
            {
                Emergency t = data[i]; data[i] = data[parent]; data[parent] = t;
                i = parent;
            }
            else break;
        }
    }

    void heapifyDown(int i)
    {
        while (true)
        {
            int l = 2 * i + 1, r = 2 * i + 2, best = i;
            if (l < size_ && higher(data[l], data[best])) best = l;
            if (r < size_ && higher(data[r], data[best])) best = r;
            if (best == i) break;
            Emergency t = data[i]; data[i] = data[best]; data[best] = t;
            i = best;
        }
    }

public:
    EmergencyHeap() { size_ = 0; arrivalCounter = 0; }

    int  size()    { return size_; }
    bool isEmpty() { return size_ == 0; }
    bool isFull()  { return size_ == MAX_EMERGENCY; }

    bool insert(int pid, int severity)
    {
        if (isFull()) return false;
        data[size_].patientId = pid;
        data[size_].severity  = severity;
        data[size_].order     = arrivalCounter++;
        heapifyUp(size_);
        size_++;
        return true;
    }

    bool extractMax(int& pid, int& severity)
    {
        if (isEmpty()) return false;
        pid = data[0].patientId;
        severity = data[0].severity;
        size_--;
        data[0] = data[size_];
        heapifyDown(0);
        return true;
    }

    // Shows the waiting list in treatment order WITHOUT disturbing the real heap
    void display()
    {
        if (isEmpty()) { cout << "  No emergency cases waiting.\n"; return; }
        EmergencyHeap copy = *this;             // work on a copy
        cout << left << setw(8) << "Rank" << setw(12) << "PatientID" << setw(10) << "Severity" << endl;
        cout << string(30, '-') << endl;
        int rank = 1, pid, sev;
        while (copy.extractMax(pid, sev))
            cout << left << setw(8) << rank++ << setw(12) << pid << setw(10) << sev << endl;
    }
};

// ===========================================================================
//          5. DISCHARGE HISTORY  ->  STACK (LIFO)  +  UNDO FEATURE
// ===========================================================================
struct DischargeRecord
{
    int     id;
    string  name;
    int     age;
    string  gender;
    string  disease;
    int     doctorId;
    int     days;
    int     bill;
    DischargeRecord* next;
};

class DischargeStack
{
private:
    DischargeRecord* top;
    int count;
public:
    DischargeStack() { top = NULL; count = 0; }
    ~DischargeStack()
    {
        while (top != NULL) { DischargeRecord* t = top; top = top->next; delete t; }
    }

    bool isEmpty() { return top == NULL; }
    int  size()    { return count; }

    void push(Patient* p, int bill)
    {
        DischargeRecord* r = new DischargeRecord;
        r->id = p->id; r->name = p->name; r->age = p->age; r->gender = p->gender;
        r->disease = p->disease; r->doctorId = p->doctorId; r->days = p->days;
        r->bill = bill;
        r->next = top;
        top = r;
        count++;
    }

    // Removes the last discharged record and returns it as a Patient (for UNDO)
    Patient* pop()
    {
        if (top == NULL) return NULL;
        DischargeRecord* r = top;
        Patient* p = new Patient(r->id, r->name, r->age, r->gender, r->disease, r->doctorId, r->days);
        top = top->next;
        delete r;
        count--;
        return p;
    }

    void display()
    {
        if (top == NULL) { cout << "  No discharge history.\n"; return; }
        cout << left << setw(7) << "ID" << setw(20) << "Name" << setw(18) << "Disease"
             << setw(6) << "Days" << setw(10) << "Bill(Rs)" << endl;
        cout << string(61, '-') << endl;
        for (DischargeRecord* r = top; r != NULL; r = r->next)   // latest first
            cout << left << setw(7) << r->id << setw(20) << r->name.substr(0, 19)
                 << setw(18) << r->disease.substr(0, 17) << setw(6) << r->days
                 << setw(10) << r->bill << endl;
    }
};

// ===========================================================================
//                          GLOBAL SYSTEM OBJECTS
// ===========================================================================
PatientBST       patients;
DoctorList       doctors;
AppointmentQueue appointments;
EmergencyHeap    emergencies;
DischargeStack   dischargeHistory;

int nextPatientId = 1001;
int nextDoctorId  = 1;

// ===========================================================================
//                          FILE LOADING
// ===========================================================================
// Splits a line like "1001|Ali|25|Male|Flu|1|0" into fields using '|'
int splitLine(const string& line, string fields[], int maxFields)
{
    stringstream ss(line);
    string item;
    int n = 0;
    while (n < maxFields && getline(ss, item, '|'))
        fields[n++] = item;
    return n;
}

void loadData()
{
    string line, f[7];

    ifstream pf(PATIENT_FILE);
    if (pf)
    {
        while (getline(pf, line))
        {
            if (splitLine(line, f, 7) == 7)
            {
                int id = atoi(f[0].c_str());
                Patient* p = new Patient(id, f[1], atoi(f[2].c_str()), f[3], f[4],
                                         atoi(f[5].c_str()), atoi(f[6].c_str()));
                if (!patients.insert(p)) delete p;
                if (id >= nextPatientId) nextPatientId = id + 1;
            }
        }
        pf.close();
    }

    ifstream df(DOCTOR_FILE);
    if (df)
    {
        while (getline(df, line))
        {
            if (splitLine(line, f, 5) == 5)
                doctors.add(atoi(f[0].c_str()), f[1], f[2], atoi(f[3].c_str()), atoi(f[4].c_str()));
        }
        df.close();
        nextDoctorId = doctors.maxId() + 1;
    }
}

void saveData()
{
    patients.saveToFile(PATIENT_FILE);
    doctors.saveToFile(DOCTOR_FILE);
}

// ===========================================================================
//                          DOCTOR MODULE
// ===========================================================================
void addDoctor()
{
    cout << "\n--- Add New Doctor ---\n";
    string name = readText("Doctor name           : ");
    string spec = readText("Specialization        : ");
    int fee     = readInt ("Consultation fee (Rs) : ", 0, 100000);
    doctors.add(nextDoctorId, name, spec, fee, 0);
    cout << "\n  Doctor added successfully. Doctor ID = " << nextDoctorId << endl;
    nextDoctorId++;
}

void doctorMenu()
{
    int ch;
    do
    {
        clearScreen();
        cout << "========== DOCTOR MANAGEMENT (Linked List) ==========\n";
        cout << " 1. Add doctor\n 2. Display all doctors\n 3. Search by specialization\n"
             << " 4. Search by doctor ID\n 5. Remove doctor\n 0. Back\n";
        ch = readInt("Choice: ", 0, 5);
        cout << endl;
        if (ch == 1) addDoctor();
        else if (ch == 2) doctors.display();
        else if (ch == 3) doctors.display(readText("Enter specialization: "));
        else if (ch == 4)
        {
            Doctor* d = doctors.find(readInt("Enter doctor ID: ", 1, 999999));
            if (d == NULL) cout << "  Doctor not found.\n";
            else cout << "  Found: Dr. " << d->name << " (" << d->specialization
                      << "), fee Rs. " << d->fee << endl;
        }
        else if (ch == 5)
        {
            if (doctors.remove(readInt("Enter doctor ID to remove: ", 1, 999999)))
                cout << "  Doctor removed.\n";
            else cout << "  Doctor not found.\n";
        }
        if (ch != 0) pauseScreen();
    } while (ch != 0);
}

// ===========================================================================
//                          PATIENT MODULE
// ===========================================================================
void registerPatient()
{
    cout << "\n--- Register New Patient ---\n";
    if (doctors.size() == 0)
    {
        cout << "  No doctors available. Please add a doctor first.\n";
        return;
    }
    string name    = readText("Patient name  : ");
    int age        = readInt ("Age           : ", 0, 120);
    int g          = readInt ("Gender (1=Male, 2=Female, 3=Other): ", 1, 3);
    string gender  = (g == 1) ? "Male" : (g == 2) ? "Female" : "Other";
    string disease = readText("Disease/Complaint : ");

    cout << "\nAvailable doctors:\n";
    doctors.display();
    int did;
    while (true)
    {
        did = readInt("Assign Doctor ID : ", 1, 999999);
        if (doctors.find(did) != NULL) break;
        cout << "  No doctor with this ID. Try again.\n";
    }
    int days = readInt("Days admitted (0 for OPD patient): ", 0, 365);

    Patient* p = new Patient(nextPatientId, name, age, gender, disease, did, days);
    patients.insert(p);
    cout << "\n  Patient registered successfully. Patient ID = " << nextPatientId << endl;
    nextPatientId++;
}

void updatePatient()
{
    int id = readInt("Enter patient ID to update: ", 1, 999999);
    Patient* p = patients.search(id);
    if (p == NULL) { cout << "  Patient not found.\n"; return; }
    printPatientHeader();
    printPatientRow(p);
    cout << "\n 1. Change disease\n 2. Change days admitted\n 3. Change doctor\n";
    int c = readInt("What to update? ", 1, 3);
    if (c == 1) p->disease = readText("New disease: ");
    else if (c == 2) p->days = readInt("New days admitted: ", 0, 365);
    else
    {
        doctors.display();
        int did = readInt("New doctor ID: ", 1, 999999);
        if (doctors.find(did) == NULL) { cout << "  Doctor not found. No change made.\n"; return; }
        p->doctorId = did;
    }
    cout << "  Record updated.\n";
}

// ----- Sorting algorithms (on an array of Patient pointers) -----
// Insertion sort by name : O(n^2), good for small/nearly sorted data
void insertionSortByName(Patient** a, int n)
{
    for (int i = 1; i < n; i++)
    {
        Patient* key = a[i];
        int j = i - 1;
        while (j >= 0 && toLower(a[j]->name) > toLower(key->name))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Selection sort by age : O(n^2)
void selectionSortByAge(Patient** a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j]->age < a[minIdx]->age) minIdx = j;
        Patient* t = a[i]; a[i] = a[minIdx]; a[minIdx] = t;
    }
}

void displaySorted(int mode)   // 1 = by name, 2 = by age
{
    int n;
    Patient** arr = patients.toArray(n);
    if (arr == NULL) { cout << "  No patients registered.\n"; return; }
    if (mode == 1) insertionSortByName(arr, n);
    else           selectionSortByAge(arr, n);
    printPatientHeader();
    for (int i = 0; i < n; i++) printPatientRow(arr[i]);
    delete[] arr;
}

void patientMenu()
{
    int ch;
    do
    {
        clearScreen();
        cout << "========== PATIENT MANAGEMENT (Binary Search Tree) ==========\n";
        cout << " 1. Register new patient\n 2. Search patient by ID      (BST search)\n"
             << " 3. Search patient by name\n 4. Display all patients      (Inorder: sorted by ID)\n"
             << " 5. Display sorted by name    (Insertion Sort)\n"
             << " 6. Display sorted by age     (Selection Sort)\n"
             << " 7. Update patient record\n 0. Back\n";
        ch = readInt("Choice: ", 0, 7);
        cout << endl;
        if (ch == 1) registerPatient();
        else if (ch == 2)
        {
            Patient* p = patients.search(readInt("Enter patient ID: ", 1, 999999));
            if (p == NULL) cout << "  Patient not found.\n";
            else { printPatientHeader(); printPatientRow(p); }
        }
        else if (ch == 3)
        {
            if (patients.searchByName(readText("Enter name (or part of it): ")) == 0)
                cout << "  No matching patient.\n";
        }
        else if (ch == 4) patients.displayAll();
        else if (ch == 5) displaySorted(1);
        else if (ch == 6) displaySorted(2);
        else if (ch == 7) updatePatient();
        if (ch != 0) pauseScreen();
    } while (ch != 0);
}

// ===========================================================================
//                    APPOINTMENT MODULE (Queue)
// ===========================================================================
void bookAppointment()
{
    cout << "\n--- Book OPD Appointment ---\n";
    int pid = readInt("Patient ID : ", 1, 999999);
    if (patients.search(pid) == NULL) { cout << "  Patient not registered.\n"; return; }
    doctors.display();
    int did = readInt("Doctor ID  : ", 1, 999999);
    if (doctors.find(did) == NULL) { cout << "  Doctor not found.\n"; return; }
    appointments.enqueue(pid, did);
    cout << "  Appointment booked. Your token number = " << appointments.size() << endl;
}

void serveAppointment()
{
    int pid, did;
    if (!appointments.dequeue(pid, did)) { cout << "  No pending appointments.\n"; return; }
    Patient* p = patients.search(pid);
    Doctor*  d = doctors.find(did);
    if (p == NULL || d == NULL)
    {
        cout << "  Skipped: patient " << pid << " or doctor " << did << " no longer exists.\n";
        return;
    }
    d->patientsTreated++;
    cout << "  Now serving: " << p->name << " (ID " << pid << ")  ->  Dr. " << d->name << endl;
    cout << "  Consultation fee: Rs. " << d->fee << endl;
}

void appointmentMenu()
{
    int ch;
    do
    {
        clearScreen();
        cout << "========== OPD APPOINTMENTS (Queue - FIFO) ==========\n";
        cout << " 1. Book appointment (Enqueue)\n 2. Serve next patient (Dequeue)\n"
             << " 3. View waiting queue\n 0. Back\n";
        ch = readInt("Choice: ", 0, 3);
        cout << endl;
        if (ch == 1) bookAppointment();
        else if (ch == 2) serveAppointment();
        else if (ch == 3) appointments.display();
        if (ch != 0) pauseScreen();
    } while (ch != 0);
}

// ===========================================================================
//                    EMERGENCY MODULE (Max-Heap)
// ===========================================================================
void addEmergency()
{
    cout << "\n--- Add Emergency Case ---\n";
    int pid = readInt("Patient ID (register first if new): ", 1, 999999);
    if (patients.search(pid) == NULL) { cout << "  Patient not registered.\n"; return; }
    cout << "  Severity: 1=Minor 2=Moderate 3=Serious 4=Severe 5=Critical\n";
    int sev = readInt("Severity (1-5): ", 1, 5);
    if (emergencies.insert(pid, sev)) cout << "  Emergency case added to priority queue.\n";
    else cout << "  Emergency queue is full!\n";
}

void treatEmergency()
{
    int pid, sev;
    if (!emergencies.extractMax(pid, sev)) { cout << "  No emergency cases waiting.\n"; return; }
    Patient* p = patients.search(pid);
    if (p == NULL) { cout << "  Skipped: patient " << pid << " no longer exists.\n"; return; }
    Doctor* d = doctors.find(p->doctorId);
    if (d != NULL) d->patientsTreated++;
    cout << "  Treating most urgent case: " << p->name << " (ID " << pid
         << "), severity " << sev << endl;
}

void emergencyMenu()
{
    int ch;
    do
    {
        clearScreen();
        cout << "========== EMERGENCY WARD (Max-Heap Priority Queue) ==========\n";
        cout << " 1. Add emergency case (Insert)\n 2. Treat most critical case (Extract Max)\n"
             << " 3. View emergency waiting list\n 0. Back\n";
        ch = readInt("Choice: ", 0, 3);
        cout << endl;
        if (ch == 1) addEmergency();
        else if (ch == 2) treatEmergency();
        else if (ch == 3) emergencies.display();
        if (ch != 0) pauseScreen();
    } while (ch != 0);
}

// ===========================================================================
//                 DISCHARGE & BILLING MODULE (Stack)
// ===========================================================================
void dischargePatient()
{
    cout << "\n--- Discharge Patient & Generate Bill ---\n";
    int pid = readInt("Patient ID: ", 1, 999999);
    Patient* p = patients.search(pid);
    if (p == NULL) { cout << "  Patient not found.\n"; return; }

    Doctor* d = doctors.find(p->doctorId);
    int docFee = (d != NULL) ? d->fee : 0;

    p->days = readInt("Total days admitted: ", 0, 365);
    int medicine = readInt("Medicine / lab charges (Rs): ", 0, 10000000);
    int roomCharges = p->days * ROOM_CHARGE_PER_DAY;
    int total = roomCharges + docFee + medicine;

    cout << "\n=============== BILL ===============\n";
    cout << " Patient    : " << p->name << " (ID " << p->id << ")\n";
    cout << " Doctor     : " << (d != NULL ? d->name : "N/A") << endl;
    cout << " Room (" << p->days << " days x " << ROOM_CHARGE_PER_DAY << ") : Rs. " << roomCharges << endl;
    cout << " Doctor fee : Rs. " << docFee << endl;
    cout << " Medicine   : Rs. " << medicine << endl;
    cout << " ------------------------------------\n";
    cout << " TOTAL      : Rs. " << total << endl;
    cout << "====================================\n";

    dischargeHistory.push(p, total);     // save to stack (for history & undo)
    patients.remove(pid);                // remove from active BST
    cout << "  Patient discharged and moved to history.\n";
}

void undoDischarge()
{
    Patient* p = dischargeHistory.pop();
    if (p == NULL) { cout << "  Nothing to undo.\n"; return; }
    if (patients.insert(p))
        cout << "  Undo successful. " << p->name << " (ID " << p->id << ") is an active patient again.\n";
    else
    {
        cout << "  Could not restore (ID already exists).\n";
        delete p;
    }
}

void dischargeMenu()
{
    int ch;
    do
    {
        clearScreen();
        cout << "========== DISCHARGE & BILLING (Stack - LIFO) ==========\n";
        cout << " 1. Discharge patient & generate bill (Push)\n"
             << " 2. View discharge history (latest first)\n"
             << " 3. Undo last discharge (Pop)\n 0. Back\n";
        ch = readInt("Choice: ", 0, 3);
        cout << endl;
        if (ch == 1) dischargePatient();
        else if (ch == 2) dischargeHistory.display();
        else if (ch == 3) undoDischarge();
        if (ch != 0) pauseScreen();
    } while (ch != 0);
}

// ===========================================================================
//                              MAIN MENU
// ===========================================================================
void showStatistics()
{
    cout << "\n--- Hospital Statistics ---\n";
    cout << " Active patients       : " << patients.size() << endl;
    cout << " Doctors               : " << doctors.size() << endl;
    cout << " Pending appointments  : " << appointments.size() << endl;
    cout << " Emergency cases       : " << emergencies.size() << endl;
    cout << " Discharged (history)  : " << dischargeHistory.size() << endl;
}

int main()
{
    loadData();

    int ch;
    do
    {
        clearScreen();
        cout << "==================================================\n";
        cout << "        HOSPITAL MANAGEMENT SYSTEM (DSA Project)   \n";
        cout << "==================================================\n";
        cout << " 1. Patient Management      [BST + Sorting]\n";
        cout << " 2. Doctor Management       [Linked List]\n";
        cout << " 3. OPD Appointments        [Queue]\n";
        cout << " 4. Emergency Ward          [Max-Heap]\n";
        cout << " 5. Discharge & Billing     [Stack]\n";
        cout << " 6. Hospital Statistics\n";
        cout << " 7. Save Data to File\n";
        cout << " 0. Save & Exit\n";
        cout << "--------------------------------------------------\n";
        ch = readInt("Enter your choice: ", 0, 7);

        if (ch == 1) patientMenu();
        else if (ch == 2) doctorMenu();
        else if (ch == 3) appointmentMenu();
        else if (ch == 4) emergencyMenu();
        else if (ch == 5) dischargeMenu();
        else if (ch == 6) { showStatistics(); pauseScreen(); }
        else if (ch == 7) { saveData(); cout << "\n  Data saved.\n"; pauseScreen(); }
    } while (ch != 0);

    saveData();
    cout << "\nData saved. Thank you for using the Hospital Management System!\n";
    return 0;
}
