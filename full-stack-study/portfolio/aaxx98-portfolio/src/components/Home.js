import "./Home.css";
import Header from "./Header";
import Intro from "./Intro";
import Project from "./Project";
import Footer from "./Footer";
import React from "react";
import Fade from "react-reveal/Fade";

const projectArray = [
    {
        key: 1,
        id: 1,
        title: "언덕을 오르는 7016",
        date: [`2018.05`, `2018.06`],
        contents:
            "인터랙티브 라이브러리 '프로세싱(Processing)'을 활용한 UX/UI 프로젝트",
        tags: ["Processing"],
        detail: {
            linkimg: "./img/7016_2.png",
            image: "./img/7016_1.png",
            link: "https://semicolon-janghyejin.github.io/js-study/smu7016/home.html",
            role: [],
        },
    },
    {
        key: 2,
        id: 2,
        title: "스택 버거(Stack Burger)",
        date: [`2019.04`, `2019.06`],
        contents: "자료구조 Stack의 원리를 배울 수 있는 햄버거 만들기 게임",
        tags: ["Java8"],
        detail: {
            linkimg: "./img/stackburger_2.png",
            image: "./img/stackburger_1.png",
            link: "https://github.com/Semicolon-JangHyeJin/stackburger",
            role: ["Java GUI를 활용한 카드 순서 맞추기 게임 구현"],
        },
    },
    {
        key: 3,
        id: 3,
        title: "반도체 제조 공정 웹 앱 ERP(Enterprise Resource Planning) System",
        date: [`2019.07`, `2020.06`],
        contents: "반도체 생산 및 납품 관리를 위한 웹 앱 ERP System",
        tags: ["Java8", "JSP", "Bootstrap", "MySQL", "Apache Tomcat"],
        detail: {
            linkimg: "./img/erp_2.png",
            image: "./img/erp_1.png",
            link: "https://github.com/Semicolon-JangHyeJin/sc-grad-erp",
            role: [
                "로그인 기능(Session을 사용한 로그인 유지기능)",
                "UI(로그인, 메인 페이지, 데이터 등록/수정/삭제/검색)",
            ],
        },
    },
];

class Home extends React.Component {
    state = {
        project: [],
    };

    componentDidMount() {
        this.setState({ project: projectArray });
    }

    render() {
        const { project } = this.state;
        return (
            <div>
                <Header></Header>
                <div className="container">
                    <Intro></Intro>
                    <div className="projects">
                        <h1>프로젝트</h1>
                        <p>프로젝트를 클릭하면 상세 정보로 이동합니다.</p>
                        {project
                            .slice(0)
                            .reverse()
                            .map(project => (
                                <Fade bottom>
                                    <Project
                                        key={project.key}
                                        id={project.id}
                                        title={project.title}
                                        date={project.date}
                                        contents={project.contents}
                                        tags={project.tags}
                                        detail={project.detail}
                                    ></Project>
                                </Fade>
                            ))}
                    </div>
                </div>
                <Footer></Footer>
            </div>
        );
    }
}

export default Home;
