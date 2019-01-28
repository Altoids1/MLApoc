#include <windows.h>
#include <iostream>
#include <string>

using namespace std;
void editor(string type_ed); // It's void, as it outputs the result into $result
bool yaynay(string question = "ERROR: Unknown question!", string goodresponse = "yes"); // Takes a question and figures if the dude said yes
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Something for dealing with colouring
string prompt(string prom = "") // Prompts for a string.
{
	if(prom != "") cout << prom << "\n>";
	SetConsoleTextAttribute(hConsole, 8);
	string data = "";
	while (data == "")getline(cin, data);
	SetConsoleTextAttribute(hConsole, 15);
	return data;
}
string authors(int thingtype = 0, string tip = ""); // Done
string title_etc(); // Done
string city(); // Done
string book_year(); // Done
string book_type(); // Done
string artc_type(); // Fini
string mag_dadt(); // Fini
void delete_first(string dotdot); // Takes a bit of weird formatting, finds it in the result, and deletes the first char of that weirdness. "  " becomes " "
string result = "";
string opt = "(Yes/No)\n>";

int main()
{
	SetConsoleTextAttribute(hConsole, 9);
	cout << "-------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "Welcome to MLApocalypse version 3.0 Beta!\nCreated for: Perdue Owl's MLA 8\n";
	cout << "This was created to help you develop your Works Cited citations without ripping your hair out at how\n";
	cout << "terrible and arcane the MLA style is.\n";
	cout << "If you would like to view the flowchart this program is based on, please visit: https://bubbl.us/7757071\n";
	cout << "Do note, however, that much of the flowchart linked here is somewhat dated and not fully representative of\n";
	cout << "what is happening in this program.\n";
	SetConsoleTextAttribute(hConsole, 9);
	cout << "-------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "What type of source are you using?\nOptions are:\n\tBook\t[Also includes press releases & pamphlets]\n\tArticle [Magazine, Scholarly, Anything in a Newspaper, etc.]\n\tTV\t[Also includes Radio]\n\tWikipedia\n\n>>";
	string Cite = "";
	cin >> Cite;
	char *Cite_ = &Cite[0u]; // All this schtick lowercases the input
	for (unsigned int a = 0; a <= Cite.length(); ++a)
	{
		Cite_[a] = tolower(Cite_[a]);
	}
	string CiteType = string(Cite_);
	if (CiteType == "book")
	{
		std::cout << "NOTE: If you gotta pamphlet, then you're in luck: It's literally the exact same as a book.\n";
		if (yaynay("Is it a sacred text of some sort, like the Bible or Bhagavad Gita?")) // Is a sacred text
		{
			if (yaynay("Is it some specific version of it (i.e King James vers.?)"))
			{
				string title = title_etc();
				while (title == "");
				string citee = city();
				while (citee == "");
				string Publisher = prompt("Who's the publisher?");
				string PubYear = prompt("What year was it published?");
				string versio = prompt("What version is it? i.e King James");
				string bookty = book_type();
				result = title + " " + citee + ": " + Publisher + ", " + PubYear + ". Print." + versio + " Vers.";
			}
			else
			{
				string title = title_etc();
				while (title == "");
				string citee = city();
				while (citee == "");
				string Publisher = "";
				cout << "Who's the publisher?\n>";
				while (Publisher == "")getline(cin, Publisher);
				cout << "What year was it published?\n>";
				string PubYear = "";
				while (PubYear == "")getline(cin, PubYear);
				string bookty = book_type();
				result = title + " " + citee + ": " + Publisher + ", " + PubYear + ". Print.";
			}
		}
		else // Not a sacred text
		{
			if (yaynay("Is there an editor?"))
			{
				editor("ed.");
			}
			else // No editor
			{
				if (yaynay("Is there a compiler?"))
				{
					editor("comp.");
				}
				else // No compiler
				{
					if (yaynay("Is there a translator?"))
					{
						editor("trans.");
					}
					else // No translator
					{
						cout << "Who's the publisher?\n>";
						string Publisher = "";
						while (Publisher == "")getline(cin, Publisher);
						string auth = authors();
						while (auth == "");
						string title = title_etc();
						while (title == "");
						string ville = city();
						while (ville == "");
						string bookannee = book_year();
						while (bookannee == "");
						string bookty = book_type();
						result = auth + ". " + title + " " + ville + ": " + Publisher + ", " + bookannee + ". " + bookty;
					}
				}
			}
		}
	}
	else if (CiteType == "article")
	{ // So it's an article.

		string auth = authors(1);
		while (auth == "");
		if (auth != "")auth = auth + ". ";
		// ^ That gets rid of any spare periods/spaces 
		// at the start
		string title = prompt("What's the title of the article? No quotes!\nIf there isn't a title, just type x.");
		if (title == "x" || title == "X")title = "";
		string printweb = artc_type();
		while (printweb == "");
		string pages = prompt("What page numbers is it on? Remember, give 120 to 130 as 120-30.\nEnter x if there's no pagination anywhere.\nIf there is some letter next to the page numbers for some reason, include that at the start.");
		if (pages == "x")pages = "";
		else pages = ": " + pages;
		// Author(s), title, pages, and Web/Print are dealt with above ^
		string ark = prompt("What type of article?\nOptions:\n\tScholarly\n\tMagazine\n\tNewspaper\n");
		char *ark_ = &ark[0u];
		for (unsigned int a = 0; a <= ark.length(); ++a) // All this schtick lowercases the input
		{
			ark_[a] = tolower(ark_[a]);
		}
		string arktype = string(ark_);
		if (arktype == "scholarly")
		{
			string journal = prompt("What's the name of the journal? Remember to italicize this later.");
			string vol = prompt("What's the volume number? Just give a normal number, like \"5\"");
			string issue = prompt("What's the issue number? Raw number again, please.");
			string year = prompt("What year was it published");
			result = auth + "\"" + title + ".\" " + journal + " " + vol + "." + issue + " (" + year + ")" + pages + ". " + printweb;
		}
		else if (arktype == "magazine")
		{
			string magazine = prompt("What's the name of the magazine? Remember to italicize this later.");
			string dadt = mag_dadt();
			while (dadt == "");
			result = auth + "\"" + title + ".\" " + magazine + " " + dadt + pages + ". " + printweb;
		}
		else if (arktype == "newspaper")
		{
			string dadt = prompt("What is the date of publication? (Give Day Mon. Year)");
			string newspaper = prompt("What is the name of the newspaper?\nIf it doesn't have the city in its name, then include the city's name [in square brackets].");
			string editio = prompt("What is the edition, if there is one? (Like, intl., natl., late, early, weekend, etc.)\nIf there is none, type X instead.");
			if (editio == "X" || editio == "x")editio = "";
			else editio = " ," + editio + " ed.";
			if (yaynay("Is it an editorial?"))
			{
				result = auth + "\"" + title + ".\" Editorial. " + newspaper + " " + dadt + editio + pages + ". " + printweb;
			}
			else
			{
				if (yaynay("Is it a letter to the editor?"))
				{
					if (title == "")
					{
						result = auth + " Letter. " + newspaper + " " + dadt + editio + pages + ". " + printweb;
					}
					else
					{
						result = auth + "\"" + title + ".\" Letter. " + newspaper + " " + dadt + editio + pages + ". " + printweb;
					}
				}
				else
				{
					if (yaynay("Is this a review?"))
					{
						string title2 = prompt("What's the name of the thing they're reviewing? Include quotes if needed.");
						string auth2 = prompt("Give the name of who wrote that thing, or at least who edited it.");
						if (yaynay("Did this guy edit it?"))
						{
							result = auth + "\"" + title + ".\" Rev. of " + title2 + ", ed. " + auth2 + ". " + newspaper + " " + dadt + editio + pages + ". " + printweb;
						}
						else
						{
							result = auth + "\"" + title + ".\" Rev. of " + title2 + ", by " + auth2 + ". " + newspaper + " " + dadt + editio + pages + ". " + printweb;
						}
					}
					else
					{
						result = auth + "\"" + title + ".\" " + newspaper + " " + dadt + editio + pages + ". " + printweb;
					}
				}
			}
		}
		else
		{
			cout << "ERROR: Unknown article type!\n";
			Sleep(INT_MAX);
			return 0;
		}
	}
	else if (CiteType == "tv")
	{
		string episode = prompt("What's the title of the episode? No quotes!");
		string nonauthors = "";
		string joblist = { // List of possible non-authory jobs the credits' might've had.
			//Kind of a temporarily solution to this.
			"directed",
			"created",
			"performed",
			"narrated"
		};
		for(int i = 0; i < 5; ++i)
		{
			if (yaynay("Do you know who " + joblist[i] + " on that show?"))
			{
				nonauthors += joblist[i] + " by " + prompt("What's their name? (First Last)") + ", ";
			}
		}

		string series = prompt("What's the name of the series? Remember to italicize this later.");
		string network = prompt("What's the name of the network? I.e. PBS, NPR, Fox ...");
		string dadt = prompt("What's the broadcast date? Day Month Year in MLA format, ex: 15 Mar. 2017\nDo not abbreviate May, June, nor July.");
		string callsign = prompt("What's the callsign of the station that broadcasted this,\n if you know what that is and can find it?\nType X if you can't find that info.");
		if (callsign == "X" || callsign == "x")callsign = "n.p."; // I can put n.p. here since the filter will find any double periods or what have you
		callsign = callsign + ", ";
		string ville = city();
		while (ville == "");
		result = "\"" + episode + ".\" " + series + ". " + network + ". " + nonauthor + callsign + ville + ". " + dadt;
		if (yaynay("Is it TV or Radio?", "tv"))
		{
			result += ". Television.";
		}
		else // Is a radio show
		{

			result += ". Radio.";
		}
	}
	else if (CiteType == "wikipedia")
	{
		cout << "Okay, that's pretty easy.\n";
		string title = prompt("What's the title of the article? No quotes!");
		string dadt = prompt("What's your access date? I.e 5 Mar. 2017 (Don't abbreviate May, June, or July)");
		string eddadt = prompt("What's the date of the most recent edit?\nYou can check that via the History tab in the top-right corner of the wiki page.");
		result = "\"" + title + "\". Wikipedia. Wikimedia Foundation, " + eddadt + ". Web. " + dadt + ". ";
	}
	else if (CiteType == "debug")
	{
		system("Color 4D");
		system("Color 2F");
		cout << "\nALERT: ELITE HACKER DETECTED!" << endl;
		result = "HACKER, ELITE. SPY KIDS 5: LAVA BOY STRIKES BACK. DISNEY, 420-666. 2017. SICK-ASS MOVIE.";
		goto END;
	}
	else
	{
		cout << "ERROR: Unknown type!\n";
		Sleep(3);
		return 0;
	}
END:
	string shit[7] = { "..","  ",":.","\"\"",",,","\'\'",",:" };
	for (int i = 0; i <= 6; ++i)
	{
		delete_first(shit[i]);
	}
	cout << "Your MLA citation is:\n\n\n";
	SetConsoleTextAttribute(hConsole, 14);
	cout << result;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\n\nSome notes, most of them pretty important:\n";
	SetConsoleTextAttribute(hConsole, 8);
	cout << "-Make sure the first line of each citation is unindented, with every following line being indented\n half an inch.";
	cout << "\n-In this font, parentheses look like this () and less-than greater-than looks like this <>. Keep that in mind.";
	cout << "\n-If it's the title of something big, like a book or a TV show, italicize. If it's something smaller,\n like a poem or an article, then quote.";
	cout << "\n-Remember to order them alphabetically, with numbers going first. Ignore \"The\" and \"A(n)\" when\n alphabetizing.";
	cout << "\n-If you have a bunch of stuff made by the same guy, keep them together and just put a \"---\" as the\n author after the first time.";
	cout << "\n-REMEMBER TO PUT A MIDDLE INITIAL OR A \", Jr.\" AT THE END OF THE FIRST NAME SLOT IF THE SOURCE HAS IT!";
	cout << "\n\nAgain, if you see an error, please email andreux47@gmail.com describing the error and where it occurred.\n";
	SetConsoleTextAttribute(hConsole, 15);
	if (yaynay("\nWould you like the citation to be copied to clipboard?\nCaution: Responding will close the program!"))
	{// Black-box alert!
		OpenClipboard(0);
		EmptyClipboard();
		HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, result.size() + 1);
		if (!hg)
		{
			CloseClipboard();
			goto ANY;
		}
		memcpy(GlobalLock(hg), result.c_str(), result.size() + 1);
		GlobalUnlock(hg);
		SetClipboardData(CF_TEXT, hg);
		CloseClipboard();
		GlobalFree(hg);
	}
ANY:
	return 0;
}
string artc_type()
{
	if (yaynay("Is this on the web or in print?(Web/Print)", "web"))
	{
		string accessdadt = prompt("What's your access date? I.e. 5 Mar. 2017\nRemember not to abbrev. May, June, or July.");
		string URL = prompt("What's the URL?\nIf you don't want to type it out here, just put in PUTURLHERE or something\nDo not include any 'http://' crap.");
		return "Web. " + accessdadt + ". <" + URL + ">";
	}
	else
	{
		return "Print.";
	}
}
string authors(int thingtype, string tip)
{
	// 0 == Book Mode, 1 == Article Mode, 2 == Editor Mode
	if (thingtype == 0) // i.e. is a book/default type and ergo relevant to this
	{
		if (yaynay("Would you call your source a \"Graphic narrative or illustrated work?\""))
		{ // So it's a manga, then?
		  // Goddamn weebs using my software
			string lastnam = prompt("Last Name of Writer:");
			string firstnam = prompt("First Name of Writer: (Include crap like \",Jr.\" here.)");
			string auth = lastnam + ", " + firstnam + ", writer";
			return auth;
		}
	}
	string dude;
	if (thingtype != 2) dude = "author";
	else if (tip == "ed.")dude = "editor";// O yeah boi it's editor time
	else if (tip == "trans.")dude = "translator";
	else if (tip == "comp.")dude = "composer";
	else dude = tip;
	cout << "How many " << dude << "s are there?\nGive it as a raw number, like 2.\n>";
	string authcount_s = "";
	cin >> authcount_s;
	int authcount = stoi(authcount_s, nullptr); // Converts input to switch-able int
	string third_auth = "";
	string second_auth = "";
	string first_auth = "";
	switch (authcount)
	{
	case 3: // Prompt for third author
		cout << "What's the third listed " << dude << "'s name?(First Last)\n>";
		while (third_auth == "")getline(cin, third_auth);
	case 2: // Prompt for second author
		cout << "What's the second listed " << dude << "'s name?(First Last)\n>";
		while (second_auth == "")getline(cin, second_auth);
	case 1: // Prompt for first author
		cout << "What's the first listed " << dude << "'s name?(Last, First [Put Jr. or whatever here if needed])\n>";
		while (first_auth == "")getline(cin, first_auth);
		if (second_auth == "")
		{
			if (thingtype == 2)return "1" + first_auth;
			return first_auth;
		}
		else if (third_auth == "")
		{
			if (thingtype == 2) return "2" + first_auth + " and " + second_auth;
			return first_auth + " and " + second_auth;
		}
		else
		{
			if (thingtype == 2)return "3" + first_auth + ", " + second_auth + ", and " + third_auth;
			return first_auth + ", " + second_auth + ", and " + third_auth;
		}
	default:
		// Either no author or a lot of them
		if (authcount > 3)
		{
			cout << "What's the first" << dude << "'s name? (Last, First)\n>";
			while (first_auth == "")getline(cin, first_auth);
			return first_auth + " et al."; // Will sometimes result in double-periods, but the filter at the end can deal
		}
		if (authcount == 0 && thingtype != 2)
		{
			if (thingtype == 0)
			{
				if (yaynay("Was it written by some organization, agency, etc.?"))
				{
					if (yaynay("Was it a government agency/department?")) // Is a gov't agency author
					{
						string govtnam = prompt("Give the gov't or state directly above this agency/department.\nFor example if it's a state agency give the full name of the state.");
						return govtnam + ". " + prompt("Now give the name of the agency/department.");
					}
					else
					{
						return prompt("Give the name of the organization that wrote it");
					}
				}
				return "n.a."; // I think? Not sure.
			}
			else
			{
				return "";
			}
		}
		else
		{
			cout << "ERROR: So you have an editor, but there's 0 of them? What?\n";
			return "ERROR";
		}
	} // end-switch
} // End authors()
string book_year()
{
	if (yaynay("Is this a press release?"))
	{
		return prompt("What date was it published? i.e 15 Mar. 2016\nDo not abbreviate May, June, or July.");
	}
	else
	{
		return prompt("What year was it published?");
	}
}
string book_type()
{
	if (yaynay("Is this an e-book?"))
	{
		return prompt("What's the edition?(i.e. Kindle Edition, etc.)") + ".";
	}
	else
	{
		return "Print.";
	}
}
string city()
{
	string citnam = prompt("What's the name of the city?");
	if(yaynay("Is the city it was published in famous?"))
	{
		return citnam;
	}
	else // Not famous
	{
		if (yaynay("Was it published in the US?"))
		{
			return citnam + ", " + prompt("What state was it published in? Give the two-letter code.");
		}
		else
		{
			return citnam + ", " + prompt("What country was it published in?");
		}
	}
}
void editor(string type_ed)
{
	string Publisher = prompt("Who's the publisher?");
	string title = title_etc();
	while (title == "");
	string ville = city();
	while (ville == "");
	string bookannee = book_year();
	while (bookannee == "");
	string bookty = book_type();
	while (bookty == "");
	string editeurs = authors(2, type_ed); // Uses the authors() function to deal with there being >1 editors
	char ed_count = editeurs[0];
	string type_eds = type_ed;
	if (ed_count != char("1"))
	{
		// So take the period out
		type_eds.erase(type_eds.size() - 1, 1);
		// and add an s in that bitch
		type_eds += "s.";
	}
	editeurs.erase(0, 1); // As well, get rid of the number at the start of the string
	while (editeurs == "");
	if (yaynay("Are you citing something the " + type_eds + " wrote themself?"))
	{
		string editorwrote = prompt("What did they write? I.e. Introduction or whatever.");
		string page = prompt("What page numbers? Remember, write 120 to 140 as 120-40");
		string auth = authors();
		while (auth == "");
		result = editeurs + ", " + type_eds + " " + editorwrote + ". " + title + " By " + auth + ". " + ville + ": " + Publisher + ", " + bookannee + ". " + page + ". " + bookty;
	}
	else // Not something specifically written by the editor/comp/trans
	{
		if (yaynay("Is there an author?"))
		{
			string auth = authors();
			while (auth == "");
			type_ed[0] = toupper(type_ed[0]); // Capitalizes it
			result = auth + ". " + title + ". " + type_eds + " " + editeurs + ". " + ville + ": " + Publisher + ", " + bookannee + ". " + bookty;
		}
		else // No Author
		{
			result = editeurs + ", " + type_eds + ". " + title + " " + ville + ": " + Publisher + ", " + bookannee + ". " + bookty;
		}
	}
}

string mag_dadt()
{
	if (yaynay("Is it published monthly?"))
	{
		return prompt("Just give the (abbrev.) month and year. I.e. Nov. 2016");
	}
	else
	{
		return prompt("Give the full date in MLA format. I.e. 5 Mar. 2016\nDon't abbrev. May, June, or July.");
	}
}
string title_etc()
{
	string title = prompt("What's the title? Remember to put a colon between the title and subtitle, if there is one.");
	if (yaynay("Is this the 2nd edition or later?"))
	{
		string edition = prompt("What's the edition?(i.e 4th or 2nd or 27th)");
		title = title + ". " + edition + " ed.";
	}
	if (yaynay("Are there multiple volumes?"))
	{
		if (yaynay("Did you cite multiple volumes?"))
		{
			string volnum = prompt("How many volumes are there? Give as a normal number, like 7");
			return title + " " + volnum + " vols.";
		}
		else
		{
			string volcited = prompt("Which volume did you cite? Give as a normal number, like 3");
			return title + " Vol. " + volcited + ".";
		}
	}
	else
	{
		return title + ".";
	}
}
//							 //
// NOT MLA RELATED FUNCTIONS //
//							 //
void delete_first(string dotdot) // Takes in string $dotdot, finds it in $result, and removes the first character of it
{
	size_t dotloc = result.find(dotdot);
	while (dotloc != std::string::npos)
	{
		result.erase(dotloc, 1);
		dotloc = result.find(dotdot);
	}
}
bool yaynay(string question, string goodresponse)
{ // Takes a question and its first answer and returns if the guy gave the first answer
  // Includes case insensitivity!
  // Default $goodresponse is "yes". Remember to have $goodresponse be lowercase!
	cout << question;// Question doesn't need to include "\n>" ;)
	if (goodresponse == "yes")cout << "(Yes/No)";
	cout << "\n>";
	string response = "";
	while (response == "")getline(cin, response);
	// Now lowercase the response
	char *response_ = &response[0u];
	for (unsigned int a = 0; a <= response.length(); ++a)
	{
		response_[a] = tolower(response_[a]);
	}
	//
	string processed_response = string(response_);
	return processed_response == goodresponse;
}
