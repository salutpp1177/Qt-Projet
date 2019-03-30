#include "planification.h"

planification::planification()
{

}

/**
 * @brief Sort two patients by priority
 * @param patient A
 * @param patient B
 * @return a flag representing whether manipulation works or not
 */
bool planification::cmp(Patient A, Patient B) {
    if (A.getDate() != B.getDate())
        return A.getDate() < B.getDate();
    return A.getDuree() + A.getIDResource().size() * 10 + A.getPriorite() * 100 >
            B.getDuree() + B.getIDResource().size() * 10 + B.getPriorite() * 100;
}


/**
 * @brief Sort a list of patients
 * @param
 * @return sorted result
 */
list<pair<Consult, int>> planification::calc(vector<Patient> &pa) {

    list<pair<Consult, int>> ans;

    //Sort by date and then sort by the algorithm
    sort(pa.begin(), pa.end(), cmp);
    int tot = 0;
    for (int l = 0; l < pa.size(); l++) {
        int r = l;
        while (r < pa.size() && pa[l].getDate() == pa[r].getDate())
            r++;
        r--;		//[l,r] consult in the same day

        /*
        * From 8:00 to 18:00, not including 18:00. A total of 40 moments, 8:00 8:15 8:30
        *  we assume  8:00=0, 8；15=15....18：00=600
        */

        /*
        *  Use unsigned long long to save the resource state,
        * the i-th bit in res[x] is 1 to indicate that the x resource is used at (i * 15 + 8:00) this time.
        */
        vector<unsigned long long> res;
        /* There are 7 types of ressources*/
        res.resize(7);

        for (int i = l; i <= r; i++) {
            /* duration for one ressource */
            int tim = pa[i].getDuree() / pa[i].getIDResource().size();

            /* Tim except 15 is taken up, indicating how many 15 minutes to take */
            tim = (tim + 14) / 15;

            /* The earliest start time of this check is also recorded by 64-bit method.*/
            int lst = 0;
            for (auto x : pa[i].getIDResource()) {
                //Set the last tim 0 to 1 (binary)
                unsigned long long tmp = (1ull << tim) - 1;
                tmp <<= lst;

                /*
                 * tmp is to take a few consecutive 15 minutes at this time,
                 * such as lst == 3, tim==3. This is the earliest check from 8:45.
                 * It takes 3 15-minutes, which is 0000111000 (binary). One represents 8:45 9:00 9:15
                 */
                bool flag = 0;
                for (int bgtime = lst; bgtime <= 40 - tim; bgtime++) {
                    //Start time from lst to 40-tim
                    Consult cst;
                    cst.setPatient(pa[i].getIdPatient());
                    if (tmp&res[x] == 0) {
                        //like 0000111000 and res[x]&==0, indicating that this section of idle is not used, can be arranged here
                        cst.setRessource(x);
                        cst.setIdConsult(tot);
                        pair<Consult, int> member;
                        member.first = cst;
                        member.second = bgtime*15 + 8*60;
                        ans.push_back(member);
                        tot++;
                        //   ans.push_back(cst, bgtime * 15 + 8 * 60);
                        lst = bgtime + tim;
                        res[x] |= tmp;
                        //                        flag = 1;
                        break;
                    }
                    tmp <<= 1;
                    flag = 1;
                }
                if (flag == 0) {
                    puts("Failed sorting");
                    // return false;
                }
            }
        }
        l = r;
    }
    return ans;

}
