#include <iostream>



// Balanserapporten (tabell 2.5) fra boken
class balanserapport{
	public:
		// ANLEGGSMIDLER
		int immaterielle_eiendeler{};								// IE = Immaterielle eiendeler
		int finansielle_anleggsmidler{};							// FE = Finansielle eiendeler
		int varige_driftsmidler{};									// VD = Varige driftsmidler
																	
		// Summen av IE, FA, VD, altså anleggsmidler
		int anleggsmidler(int IE, int FA, int VD){					
			int sum_am = IE + FA + VD;
			return sum_am;
		}
		
		// OMLØPSMIDLER
		int varelager{};				// VL = Varelager
		int kundefordringer{};			// KF = Kundefordringer
		int andre_fordringer{};			// AF = Andre fordringer
		int bank{};						// B = Bank

		// Summen av VL, KF, AF, B, altså omløpsmidler
		int omløpsmidler(int VL, int KF, int AF, int B){
			int sum_om = VL + KF + AF + B;
			return sum_om;
		}
		
		// SUM EIENDELER
		int EIENDELER(int IE, int FA, int VD, int VL, int KF, int AF, int B){
			int OM = omløpsmidler(VL, KF, AF, B);
			int AM = anleggsmidler(IE, FA, VD);
			int sum_eiendeler = OM + AM;
			return sum_eiendeler;

		}
		//-------------------------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>


		// EGENKAPITAL
		int inskutt_egenkapital{};			// IEK = Inskutt egenkapital
		int opptjent_egenkapital{};			// OEK = Opptjent egenkapital

		// Summen av IEK og OEK, altså egenkapital
		int egenkapital(int IEK, int OEK){
			int sum_EK = IEK + OEK;
			return sum_EK;
		}
		
		// Summen av langsiktig gjeld
		int langsiktig_gjeld(int LG){		// LG = Langsiktig gjeld
			return LG;
		}

		
		// KORTSIKTIG GJELD
		int leverandør_gjeld{};			// LEV = Leverandørgjeld
		int offentlige_avgifter{};		// OFF = Skyldig offentlige avgifter
		int utbytte{};					// UTB = Utbytte
		int betalbar_skatt{};			// BB = Betalbar skatt
		int annen_kortsiktig_gjeld{};	// AKG = Annen kortsiktig gjeld

		// Sum kortsiktig gjeld
		int kortsiktig_gjeld(int LEV, int OFF, int UTB, int BB, int AKG){
			int sum = LEV + OFF + UTB + BB + AKG;
			return sum;
		}

		// SUM GJELD
		int gjeld(int LG, int LEV, int OFF, int UTB, int BB, int AKG){
			int sumLG = langsiktig_gjeld(LG);
			int sumKG = kortsiktig_gjeld(LEV, OFF, UTB, BB, AKG);
			int sum_gjeld = sumLG + sumKG;
			return sum_gjeld;

		}

		// SUM EGENKAPITAL OG GJELD
		int egenkapitalgjeld(int IEK, int OEK, int LG, int LEV, int OFF, int UTB, int BB, int AKG){
			int EK = IEK + OEK;
			int sum_egenkapital = egenkapital(EK, IEK);
			int sum_gjeld = gjeld(LG, LEV, OFF, UTB, BB, AKG);
			int EKG = sum_egenkapital + sum_gjeld;
			return EKG;

		}
		//-------------------------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>

};



// Resultatregnskapet (tabell 2.8) fra boken
class resultatrapport{
	public:
	// DRIFTSINNTEKTER
	int salgsinntekter{};					// SI = Salgsinntekter
	int andre_driftsinntekter{};			// AD = Andre driftsinntekter

	// Sum driftsinntekter
	int driftsinntekter(int SI, int AD){
		int sum_driftsinntekter = SI + AD;
		return sum_driftsinntekter;
	}

	// DRIFTSKOSTNADER
	int vareforbruk{};					// VF = Vareforbruk
	int lønnskostnader{};				// LK = Lønnskostnader
	int ordinære_avskrivninger{};		// OAVS = Ordinære avskrivninger
	int andre_driftskostnader{};		// AD = Andre driftskostnader

	// sum driftskostnader
	int driftskostnader(int VF, int LK, int OAVS, int AD){
		int sum = VF + LK + OAVS + AD;
		return sum;
	}

	// ORDINÆRT RESULTAT
	int driftsresultat{};					// DR = Driftsresultat
	int renteinntekter{};					// RI = Renteinntekter
	int øvrige_finansinntekter{};			// ØFI = Øvrige finansinntekter
	int ordinertresultat_fsk{};				// ORFSK = Ordinært resultat før skatt
	int skatt{};							// S = Skatt
	
	// sum ordinært resultat
	int ordinert_resultat(int DR, int RI, int ØFI, int ORFSK, int S){
		int sum = DR + RI + ØFI + ORFSK + S;
		return sum;
	}

	// DISPONERING AV ÅRSRESULTAT
	int til_egenkapital(int TEK){
		return TEK;
	}

	int utbytte(int UTB){
		return UTB;
	}

};



// DEFINISJON 2.8 - LAGERLIGNINGEN
int lagerlikningen(int IB_varelager, int innkjøp_varer, int forbruk_varer){
	int UB_varelager = IB_varelager + innkjøp_varer + forbruk_varer;
	return UB_varelager;
}

// DEFINISJON 2.9 - Lineære avskrivninger
int årlige_Lavskrivninger(int anskaffelsesverdi, int antattrestverdi, int forventet_levetid){
	int linearAVS = (anskaffelsesverdi-antattrestverdi) / forventet_levetid;
	return linearAVS;
}

// DEFINISJON 2.10 - Saldoavskrivninger
int ASAVS(int vvpb, int pi, int ss){		// ASAVS = Årlige Saldoavskrivninger
	// vvpb = verdi ved periodens begynnelse
	// pi = periodens investeringer
	// ss = saldosats
	int sum_asavs = (vvpb + pi) * ss;
	return sum_asavs;
}



// EXECUTING FUNCTIONS FROM CLASSES
void anleggsmidler(){
	// Object for my class
	balanserapport BALOBJ;

	// Necessary variable declaration
	BALOBJ.immaterielle_eiendeler = 10;
	BALOBJ.finansielle_anleggsmidler = 13;
	BALOBJ.varige_driftsmidler = 4;

	int IE = BALOBJ.immaterielle_eiendeler;
	int FA = BALOBJ.finansielle_anleggsmidler;
	int VD = BALOBJ.varige_driftsmidler;

	// ANLEGGSMIDLER FUNKSJON
	int AM = BALOBJ.anleggsmidler(IE, FA, VD);
	std::cout << ":: [+]-> Anleggsmidler == " << AM << "\n";
}


void eiendeler(){
	// Object for my class
	balanserapport BALOBJ;

	// Necessary variable declaration
	// Anleggsmidler
	BALOBJ.immaterielle_eiendeler = 10;
	BALOBJ.finansielle_anleggsmidler = 13;
	BALOBJ.varige_driftsmidler = 4;
	// Omløpsmidler
	BALOBJ.varelager = 5;
	BALOBJ.kundefordringer = 8;
	BALOBJ.andre_fordringer = 4;
	BALOBJ.bank = 6;

	// variable definitions.
	int IE = BALOBJ.immaterielle_eiendeler;
	int FA = BALOBJ.finansielle_anleggsmidler;
	int VD = BALOBJ.varige_driftsmidler;

	int VL = BALOBJ.varelager;
	int KF = BALOBJ.kundefordringer;
	int AD = BALOBJ.andre_fordringer;
	int B = BALOBJ.bank;


	// EIENDELER FUNKSJON
	int E = BALOBJ.EIENDELER(IE, FA, VD, VL, KF, AD, B);
	std::cout << ":: [+]-> Eiendeler == " << E << "\n";

}



int main(){

	

	return 0;
}
