#ifndef _MAPPINGS_H_
#define _MAPPINGS_H_

#define NUM_LETTERS 26
#define NUM_POSSIBLE_ROTORS 10
#define NUM_POSSIBLE_REFLECTORS 5

static char ROTOR_TABLES[NUM_POSSIBLE_ROTORS][NUM_LETTERS + 1] = {
    {"rebaxlptusoikhnyfmwvdqczgj"},
    {"mjstnegzqirukdhpolcvaxwyfb"},
    {"brdmcasjklegntvquywhxipfoz"},
    {"kuaynhtqisjfzmprgocvlxbdwe"},
    {"zrbsmltaoeukgnivwchpdqyjfx"},
    {"rnwtsvxiupbjeadkmlzhfqygoc"},
    {"ydgufsinaewjplzkbtcmrqvxho"},
    {"alduwjpqkyhtvbngsoferxmzci"},
    {"wnuavlykxtphbrizjocmfedsgq"},
    {"jfbqenduoaxsrvymctizpwklhg"},
};

static char REFLECTOR_TABLES[NUM_POSSIBLE_REFLECTORS][NUM_LETTERS + 1] = {
    {"hydcvuqawxpzronkgmtsfeijbl"},
    {"xqmpfeonkwirchgdblyvztjasu"},
    {"bagtircsekjzwvpoufhdqnmyxl"},
    {"ujeqcrwvmbosiykxdflzahgpnt"},
    {"mdvbhqreuzlkastxfgnoicypwj"},
};

#endif // _MAPPINGS_H_
