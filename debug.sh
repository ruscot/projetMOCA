#!/bin/bash
selection(){
	echo "####################################"
	echo "#	   -AFL	   -Valgrind	   #"
	echo "#		-Quit		   #"
	echo "####################################"
	echo
	echo "Saisir le mode de debug :"
	read saisie
	val_ret=$saisie
}

AFL_prog(){
	make clean
	source setup_afl/installe_afl.sh
	make LIBS=d AFL=1
	afl-fuzz -i afl_in/ -o afl_out/ ./main @@
}

Valgrind_prog(){
	echo "-------------------------------------------------------------------------------------------------------------------------------------------------"
	ls donnees
	echo "-------------------------------------------------------------------------------------------------------------------------------------------------"
	echo "Nom du fichier :"
	read fichier
	make clean
	case $1 in
		d)
		make LIBS=d DEBUG=1
		valgrind --log-file=Resultat_valgrind/Resultat_Dynamique.txt ./main donnees/$fichier
		;;
		s)
		make LIBS=s DEBUG=1
		valgrind --log-file=Resultat_valgrind/Resultat_Statique.txt ./main donnees/$fichier
		;;
	esac
}


val_ret=""
while [[ $val_ret != "Quit" ]]
do
	selection
	case $val_ret in
		AFL)
			AFL_prog
		;;
		Valgrind)
			echo "Choisir option de linkage de la bibliothèque"
			echo " Statique - s	Dynamique - d "
			read option
			Valgrind_prog $option
		;;
		Quit);;
		*)
			echo "Aucun débug connu ! Veuillez selection les commandes ci dessous"
		;;
	esac
done

