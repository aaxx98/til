import "./Intro.css";
const intro_contents = [
    "상명대학교 컴퓨터과학과 (2017.03~2021.02)",
    "풀스택 개발자를 목표로 공부중입니다.",
];
function Intro() {
    return (
        <div className="intro">
            <h1>소개</h1>
            <ul>
                {intro_contents.map(e => {
                    return <li>{e}</li>;
                })}
            </ul>
        </div>
    );
}
export default Intro;
