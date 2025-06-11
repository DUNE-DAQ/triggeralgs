treelite_compmodel_classifier_xgboost.so: main.o
	gcc -shared -O3 -o treelite_compmodel_classifier_xgboost.so main.o -std=c99 
main.o: main.c
	gcc -c -O3 -o main.o main.c -fPIC -std=c99 
