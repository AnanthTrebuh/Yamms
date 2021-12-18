HUBERT Nathan
LESCORBIE Valentin 


Comment Joué : 
	indiqué le nombre de joueur. 
	chaque joueur va pouvoir entré son nom 
	la partie se lance et le premier lancer est afficher
	on bloque les des en indiquant quel dés on veux bloqué via sont numéro de 1 à 5. 1 étant le plus a gauche
	à la fin des 3 lancés l'affichage des figure possible apparait et on voit le score potentiel que peut rapporté chaque figure avec les lancer de des actuel. 
	le joueur choisi la figure qu'il veux faire en rentrant le numéro de la figure inscrit a gauche de la ligne. 
	c'est maintenant au tour du joueur suivant. 
	les tours s'enchaine jusqu'à ce qu'il n'y ai plus de figure à faire.
	quand tout les tours sont passés ont affiche le score de tout les joueurs et celui avec le plus grand score est mentionné et remporte la partie.


Classe 
	Game :
	- contient un tableau de joueurs et un lancer
	Les méthodes :
	- Un constructeur
	- initPlayer() qui initialise les joueur en demandant combien de joueur et en les créant et les ajoutant au tableau de joueurs
	- turnOfGame()appel OnePlayerTurn pour chaque joueur 
	- getPlayer() qui renvoie le tabelau de players
	- affichePlayerGame() qui affiche les information de chaque joueur qui joue 
	- initDice() qui initialise les des a _keep = false
	- onePLayerTurn() qui fait un tours de jeu pour le joueur avec les trois lancé
	- chooseFigure(Player& p) qui permet de choisir la figure qu'on souhaite faire avec le lancer actuel
	- calculeScore() qui appel la focntion calculScore de chaque joueur 
	- letsPlay() qui correspond a une partie avec 13 tours pour chaque figure, le calcul du score et l'affichage du joueur avec le plus de points 
	- theWinnerIs() qui cherche dans la liste des joueurs le joueurs avec le plus de points 

	Player : 
	- contient un identifiant, un nom, un score, un tableau de figure faite et un tabelau de figure à faire
	Les méthodes : 
	- Un constructeur
	- un Constructeur par défault
	- Un constructeur par copie
	- une redéfinition de l'opérateur égale
	- calculScore() qui calcule le score du joueur, regarde le score de chaque Figure et l'ajoute au score, si la figure viens de la partieSupérieur on l'ajoute à une autre variable pour vérifié si le score arrive ou dépasse 63 pour offrir une prime au Score
	- :addFigure(int i, std::vector<int> dices) qui ajoute une figure se trouvant dans le tableau des figure a faire vers le tableau des figure faite en lui ajoutant son tabelau d'occurence et en supprimant la figure à faire du tableau de figure à faire
	- getScore() qui renvoie le score du joueur
	- addFigureTodo() qui initialise le tableau de figure à faire 
	- getFigureTodo() qui renvoie le tableau de figure à faire
	- getName() qui renvoie le nom du joueur
	- afficheFigureToDo(std::vector<int> dice) qui affiche les figure à faire en indiquant aussi le nombre de point qui peuvent être fait avec le lancer actuel
	- affichePlayer() qui affiche les information sur le joueur

	Lancer : 
	- contient un tableau de des 
	Les méthodes : 
	- Lancer() constrtucteur creant la classe lancer avec 5 des 
	- jet()   qui lance tout les dés qui ne sont pas bloqué pour avoir un nouveau jeu de dés
	- affiche() qui fait un magnifique affiche console du lancer de dés en ligne en fonction de la valeur de chaque dés
	- getDice() qui renvoie la liste des dés
	- getTabOccur() qui crée un tableau d'occurence par rapport à l'état actuel des dés du lancer
	- resetDice() qui remet tout les des à _keep = false

	Dice : 
	- contient un identifiant, une valeur et un boolean disant si le des est bloqué ou non. 
	Les méthodes : 
	- un constructeur
	- un constructeur par copie 
	- un constructeur par défault
	- un destructeur
	- la redéfinition de l'opérateur égale
	- jet() qui attribue une valeur aléatoire entre 1 et 6 au des et le mettre dans son attribut _valeur
	- getteur sur chaque attribut 
	- setteur sur l'attribut _keep

	Figure : 
	classe mère de toute les figures
	- contient un nom, un score, un tableau d'occurence de int 
	Les Méthodes : 
	- calculScore qui est en virtual 
	- isFigure qui est en virtual et détermine si la figure est valide
	- getteur sur attribut score et nom
	- setteur sur le vector<int> de lancer

	Chance : hérite de Figure 

	Full : herite de Figure, redéfini isFigure et calculScore

	PartieSupérieur : herite de Figure et a un template pour savoir a quoi correspond la partie supérieur, 1 ou 2 ou ...
	redefini le calcul de score 

	PetiteSuite et GrandeSuite : hérite de Figure et redéfinissent calculScore et isFigure

	SameDice : hérite de Figure et a un template correspondant au nombre de dés devant être identique pour que la figure soit validé
	redéfini calculScore et isFigure

	Brelan et Carre : herite de SameDice avec une valeur pour le template différente, respectivement 3 et 4.

	Yahtzee : hérite de SameDice avec une valeur de template de 5 et redéfini calculeScore.