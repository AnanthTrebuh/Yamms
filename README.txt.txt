HUBERT Nathan
LESCORBIE Valentin 

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
