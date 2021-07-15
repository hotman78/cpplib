inline string replace(string str, string before, std::string after) {
	string::size_type  Pos(str.find(before));
	while (Pos != std::string::npos) {
		str.replace(Pos, before.length(), after);
		Pos = str.find(before, Pos + after.length());
	}
	return str;
}
inline vector<string> split(string s, string delim) {
	vector<string> elems;
	s=replace(s, "#", "HASH");
	s=replace(s, delim,"#");
	stringstream ss(s);
	string item;
	while (getline(ss, item, '#')) {
		elems.push_back(replace(item, "HASH", "#"));
	}
	return elems;
}