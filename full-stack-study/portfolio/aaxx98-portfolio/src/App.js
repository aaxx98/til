import logo from "./logo.svg";
import { HashRouter, Route } from "react-router-dom";
import Detail from "./routes/Detail";
import Home from "./components/Home";

function App() {
    return (
        <HashRouter>
            <Route path="/" exact={true} component={Home} />
            <Route path="/project/:project" component={Detail} />
        </HashRouter>
    );
}

export default App;
