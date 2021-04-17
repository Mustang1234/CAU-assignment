# CAU-assignment
suc jae nae gi yong
20210800김효준 기컴프 개인과제
제 생각에 bangtal 의 각 코드는 해당 코드를 즉각적으로 실행시키는 것이 아니라 콘솔에서 논리를 마치고 게임화면에서 변화를 주기에 windows.h의 Sleep(); 과 호환이 좋지 못합니다.
예를 들면 각 오브젝트가 보였다 0.5초 뒤에 사라지는 등의 움직임은 묘사하기가 어렵습니다.
그래서 반복문으로 최대한 windows.h의 Sleep(); 과 비슷하게 코드를 만들어서 AIPlayer들의 사고하는 시간정도 등등은 최대한 구현하였지만 모든 의도된 기능을 구현하지는 못하였습니다.
또한 방탈게임 내부에 텍스트나 숫자를 출력하는 기능은 현재 지원하지 않으므로 showMessage("%d가 %d카드를 %d개 놓았습니다",a,b,c); 이나 오브젝트가 나타났다 사라지기등 구현할 수 없는 기능은 콘솔창으로 구현하였습니다.
 그리고 게임 화면 죄측 하단에 보면 Rules 버틑이 있고 클릭하면 
 Rules : The numbers on the cards are its rank. Choose cards with same rank. Then first round goes. When your turn comes again, you can either play the same
 number of cards but lower in rank than the former played, or pass. Once everyone has passed, the round is finished. The last player is then able to play a 
 set of cards to start another round. If one has no card, that's the winner. Good luck.이라는 메시지가 뜹니다.
 이것은 당연히 이 게임의 규칙이며 게임 중간중간 클릭하여 확인할 수 있도록 하였습니다.
 
 감사합니다.
