#include <iostream>
3: #include <iomanip>
4: #include <fstream>
5: #include <string>
6: using namespace std;
7: // Function prototypes
8: void addContacts();
9: void viewContacts();
10: void searchContact();
11: void editContact();
12: void deleteContact();
13:
14: int main(){ //Main Function
15: system("cls");
16: bool run=true;
17: do{
18: int Option; //Main menu
19: cout << "----------------------Address Book-----------------------------" << endl;
20: cout << "n";
21: cout << "What would you like to do?" << endl;
22: cout << "1.) Add Contact" << endl;
23: cout << "2.) Edit Contact" << endl;
24: cout << "3.) Delete Contact" << endl;
25: cout << "4.) View All Contacts" << endl;
26: cout << "5.) Search Address Book" << endl;
27: cout << "6.) Exit" << endl << endl;
28: cout << "Choose an option: ";
29: cin >> Option;
30: cin.ignore();
31: switch (Option){
32: case 1:
33: addContacts();
34: break;
35: case 2:
36: editContact();
37: break;
38: case 3:
39: deleteContact();
40: break;
41: case 4:
42: viewContacts();
43: break;
44: case 5:
45: searchContact();
46: break;
47: case 6:
48: run = false;
49: break;
50: default:
51: cout << "Please Choose between 1 to 6" <<endl;
52: int main();
53: }
54: } while(run);
55: cout << "Program Terminated";
56: }
57:
58: void addContacts(){ //Function for adding contacts.
59: system ("cls");
60: string Fname, Lname, Address, Contact, list, name, Fname2, Lname2, Address2, Contact2;
61: double counter, number;
62: cout << "----------------------Address Book-----------------------------" << endl << endl;
63: cout << "Do not use spaces if entry has 2 or more words ex: KyleAdrian" << endl;
64: cout << "Enter 'quit' at First name to quit" << endl << endl;
65: cout << "Enter First Name: ";
66: getline(cin, Fname);
67: if (Fname == "quit")
68: main();
69: cout << "Enter Last Name: ";
70: getline(cin, Lname);
71: cout << "Enter Address: ";
72: getline(cin, Address);
73: cout << "Enter Contact Number: ";
74: getline(cin, Contact);
75:
76: ifstream asd("AddressBook.txt");
77: while(asd >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2){
78: if (counter == 100){
79: cout << "Invalid Max number of contacts reached (100).";
80: main ();
81: }
82: else number = counter;
83: }
84: ofstream adb("AddressBook.txt", ios::app);
85: number = number + 1;
86: adb << number << " " << Fname << " " << Lname
87: << " " << Address << " " << Contact << endl;
88: system("pause");
89: system("cls");
90: }
91:
92: void viewContacts(){ //Show all entries in the data base.
93: system("cls");
94: double counter;
95: string Fname, Lname, Address, Contact;
96: ifstream addressbook("AddressBook.txt");
97: cout << "Entry #" << setw(17) << "First Name" << setw(23)<< "Last Name" << setw(23) <<"Address"<< setw(29)<<"Contact"<< endl << endl;
98: while (addressbook >> counter >> Fname >> Lname >> Address >> Contact){
99: cout << setw(3)<< counter << setw(18)<< Fname << setw(25) << Lname << setw(25) << Address << setw(30) << Contact << endl;
100: }
101: cout << endl;
102: system ("pause");
103: system ("cls");
104: }
105:
106: void searchContact(){ //Allow to specific entry.
107: system("cls");
108: int choice;
109: double counter, number;
110: string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2;
111:
112: cout << "----------------------Address Book-----------------------------" << endl << endl;
113: cout << "---Search Address Book---" << endl;
114: cout << "1.) First name" << endl;
115: cout << "2.) Last name" << endl;
116: cout << "3.) Address" << endl;
117: cout << "4.) Contact " << endl;
118: cout << "Enter Choice: ";
119: cin >> choice;
120: switch (choice){
121: case 1:
122: cout << "Enter First Name: ";
123: cin >> Fname;
124: cout << endl;
125: break;
126: case 2:
127: cout << "Enter Last Name: ";
128: cin >> Lname;
129: cout << endl;
130: break;
131: case 3:
132: cout << "Enter Address: ";
133: cin >> Address;
134: cout << endl;
135: break;
136: case 4:
137: cout << "Enter Contact: ";
138: cin >> Contact;
139: cout << endl;
140: break;
141: default:
142: cout << "Please Enter choice from 1 to 4";
143: searchContact();
144: }
145: ifstream search("AddressBook.txt");
146: if (choice==1){
147: while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2){
148: if(Fname == Fname2){
149: cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl << endl;
150: }
151: }
152: }
153: if (choice==2){
154: while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2){
155: if(Lname == Lname2){
156: cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl << endl;
157: }
158: }
159: }
160: if (choice==3){
161: while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2){
162: if(Address == Address2){
163: cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl <<endl;
164: }
165: }
166: }
167: if (choice==4){
168: while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2){
169: if(Contact == Contact2){
170: cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl << endl;
171: }
172: }
173: }
174: system ("pause");
175: system ("cls");
176: }
177:
178: void editContact(){ //This part allows you to edit the entries.
179: system("cls");
180: int choice;
181: double counter, number;
182: string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2, choice3;
183: ifstream edit("AddressBook.txt");
184: ofstream temp("Temp.txt", ios::app);
185: cout << "Please type the Entry number that you wish to edit: ";
186: cin >> choice;
187: cout << endl;
188: if (choice==0 || choice > 100){
189: cout << "Error, wrong entry";
190: system("pause>0");
191: editContact();
192: }
193: while (edit >> counter >> Fname2 >> Lname2>> Address2 >> Contact2){
194: if (counter==choice){
195: cout << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl<<endl;
196: cout << "Is this the contact that you wish to edit? (y or n) ";
197: cin >> choice3;
198: cout <<endl;
199: }
200:
201: if (choice3=="n") {
202: main();
203: }
204: if (choice3=="y"){
205: if (counter<choice){
206: temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
207: }
208: if (counter==choice){
209: cout << "Enter New First name: ";
210: cin >> Fname;
211: cout << "Enter New Last name: ";
212: cin >> Lname;
213: cout << "Enter New Address: ";
214: cin >> Address;
215: cout << "Enter New Contact: ";
216: cin >> Contact;
217:
218: temp << choice << " " << Fname << " "<< Lname << " " << Address << " " << Contact << endl;
219: }
220: if (counter > choice){
221: temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
222: }
223: }
224: }
225:
226:
227: edit.close();
228: temp.close();
229:
230:
231: if (remove("AddressBook.txt")==0){
232: cout << "Succesful Removing File" << endl;
233: }else{
234: cout << "Error removing"<< endl;
235: }
236: if(rename("Temp.txt", "AddressBook.txt")==0){
237: cout << "Succesful Renaming file"<< endl;
238: }else{
239: cout << "Error renaming"<<endl;
240: }
241: system("pause");
242: system("cls");
243: }
244:
245: void deleteContact(){ //This function allow to delete entries one by one.
246: system("cls");
247: int choice;
248: double counter, number;
249: string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2,choice3;
250: ifstream edit("AddressBook.txt");
251: ofstream temp("Temp.txt", ios::app);
252: cout << "Please type the Entry number that you wish to delete: ";
253: cin >> choice;
254: cout << endl;
255:
256: while (edit >> counter >> Fname2 >> Lname2>> Address2 >> Contact2){
257: if (counter==choice){
258: cout << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl<<endl;
259: cout << "Is this the contact that you wish to delete? (y or n) ";
260: cin >> choice3;
261: cout << endl;
262: }
263: if (choice3=="n") {
264: main();
265: }
266: if (counter<choice){
267: temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
268: }
269: if (counter > choice){
270: temp << counter - 1 << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
271: }
272: }
273:
274:
275: edit.close();
276: temp.close();
277:
278:
279: if (remove("AddressBook.txt")==0){
280: cout << "Succesful Removing File" << endl;
281: }else{
282: cout << "Error removing"<< endl;
283: }
284: if(rename("Temp.txt", "AddressBook.txt")==0){
285: cout << "Succesful Renaming file"<< endl;
286: }else{
287: cout << "Error renaming"<<endl;
288: }
289: system("pause");
290: system("cls");
291: }
292:
