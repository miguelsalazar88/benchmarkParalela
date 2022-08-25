#!/usr/bin/perl

# Fecha: 23 de Agosto de 2022
# Autor: Miguel Salazar di Colloredo
# Tem: Ejecución Automatizada de Benchmark 

# Vector para los ejecutables
@benchmarks = ("bench_project", "bench_project_rnd");

# Vector para las cargas  
@cargas = ("100","200","300");

# Numero de Repeticiones
$n = 2;

# Se almacena la ubicacion
$Path = "/home/miguel/Desktop/computacion_paralela/benchmarkParalela/";

# Se itera sobre la cantidad de ejecutables,
# la cantidad de cargas y la cantidad de 
# repeticiones

foreach $exes (@benchmarks){
    foreach $carga (@cargas){
        # Se crea una carpeta para almacenar los datos
        $file = "soluciones/".$exes."-size".$carga.".txt\n";
        printf("$Path$exes$file");
        for ($i = 0; $i<$n; $i++){
            #printf("$Path$exes $carga \n");
            system("$Path$exes $carga >> $file");
        }
    }
}


