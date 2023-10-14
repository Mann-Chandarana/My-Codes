import { Text } from "react-native";
import ExpensesOutput from "../components/ExpensesOutput/ExpensesOutput";
import { useContext } from "react";
import { ExpensesContext } from "../stores/expenses-context";

const AllExpenses = ()=>{
    
    const expenseCtx = useContext(ExpensesContext);

    return <ExpensesOutput 
    expenses={expenseCtx.expenses} 
    expensesPeriod="total"
    fallback="No registered expenses found!"
    />
}

export default AllExpenses;