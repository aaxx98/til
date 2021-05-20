import logo from "./logo.svg";
import "./App.css";
import Header from "./components/Header";
import Intro from "./components/Intro";
import Project from "./components/Project";

function App() {
    return (
        <div>
            <Header></Header>
            <div className="container">
                <Intro></Intro>
                <div className="projects">
                    <h1>프로젝트</h1>
                    <Project
                        key={3}
                        id={3}
                        title="반도체 제조 공정 ERP(Enterprise Resource Planning) 웹 프로젝트"
                        date={[`2019.07`, `2020.06`]}
                        contents="반도체 생산 및 납품 관리를 위한 가상 ERP System"
                        tags={["Java8", "JSP", "Bootstrap", "MySQL"]}
                    ></Project>
                    <Project
                        key={2}
                        id={2}
                        title="스택 버거(Stack Burger)"
                        date={[`2019.04`, `2019.06`]}
                        contents="자료구조 Stack의 원리를 배울 수 있는 햄버거 만들기 게임"
                        tags={["Java8"]}
                    ></Project>
                    <Project
                        key={1}
                        id={1}
                        title="언덕을 오르는 7016"
                        date={[`2018.05`, `2018.06`]}
                        contents="인터랙티브 라이브러리 '프로세싱(Processing)'을 활용한 UX/UI 프로젝트"
                        tags={["Processing"]}
                    ></Project>
                </div>
            </div>
        </div>
    );
}

export default App;
