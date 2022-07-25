% Estudiantes:
% Emmanuel D. Solis - B97670
% Jonathan Cespedes - B41713

% ----------- Hechos -----------
% Dia o Noche
hay_luz_solar(si).

% Despejado o Nublado
esta_despejado(si).

% Momento del Dia.
esta_amaneciendo(si).
es_medio_dia(si).
esta_atardeciendo(si).
es_noche(si).

% Tierra a la vista
se_ve_tierra(si).

% ----------- Reglas - Sistema -----------
% Usar el Reflejo del Agua
usar_reflejo_agua(X, Y):-
    write("Deberia usar el reflejo del agua para navegar? "),
    hay_luz_solar(X),
    esta_despejado(Y).

% Usar las Estrellas.
usar_estrellas(X, Y):-
    write("Deberia de usar las estrellas para navegar? "),
    es_noche(X),
    esta_despejado(Y).

% Acostarse sobre el barco para escuchar el oleaje.
acostarse_sobre_barco(X, Y):-
    write("Deberia acostar sobre el barco para escuchar el oleaje? "),
    es_noche(X),
    \+ esta_despejado(Y).

% Saber si debo memorizar la direccion del viento y el oleaje para usarlo el resto del dia.
memorizar_direccion_viento_oleaje(X, Y):-
    write("Deberia memorizar la direccion del viento y el oleaje? "),
    esta_amaneciendo(X),
    esta_atardeciendo(X),
    esta_despejado(Y).

% Saber si en lugar de memorizar debo usar las direcciones memorizadas.
usar_direcciones_memorizadas(X):-
    write("Debe usar las direcciones memorizadas para navegar? "),
    es_medio_dia(X).
    
terminar_navegacion(X):-
    write("Su viaje/escala ha terminado? "),
    se_ve_tierra(X).

